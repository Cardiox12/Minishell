/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 02:18:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/11/22 20:00:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "ft_math.h"
# include "ft_strings.h"
# include "ft_ctypes.h"
# include "types.h"

extern int g_quote_parity_error;
typedef struct		s_token
{
	int				type;
	char			*value;
	size_t			index;
}					t_token;

typedef struct		s_queue
{
	struct s_queue	*next;
	t_token			token;
}					t_queue;

typedef struct		s_lexer
{
	int				state;
	size_t			index;
	t_queue			*head;
	char			*input;
}					t_lexer;

enum	e_states
{
	IN_STRING = 0x01,
	IS_COMMAND = 0x01 << 1U,
	IS_FD = 0x01 << 2U,
	IS_ARGUMENT = 0x01 << 3U,
	IS_SHIFTED = 0x01 << 4U
};

# define COMMAND 1
# define STRING 2
# define OPTION 3
# define PIPE 4
# define OPERATOR 5
# define ENV_VARIABLE 6
# define REDIRECTION 7
# define RAW_STRING 8
# define FILE_DESCRIPTOR 9
# define ARGUMENT 10

# define ARR_ALL_TOK_SIZE 10
# define ARR_NON_TERM_SIZE 8
# define ARR_TERM_SIZE 2
# define LEXER_CALLBACK_SIZE 10

# define SYM_QUOTE '"'
# define SYM_SIMPLE_QUOTE '\''
# define SYM_PIPE '|'
# define SYM_OPERATOR ';'
# define SYM_ENV_VAR '$'
# define SYM_R_REDIR '>'
# define SYM_L_REDIR '<'
# define SYM_EQUAL '='
# define SYM_ESC '\\'
# define ESC_CHARSET "$\"\\"
# define ESC_BASE_CHARSET "\""
# define ESC_IMPROVED_CHARSET "\\$"

static const int g_all_tokens[ARR_ALL_TOK_SIZE] = {
	COMMAND,
	STRING,
	OPTION,
	PIPE,
	OPERATOR,
	ENV_VARIABLE,
	REDIRECTION,
	RAW_STRING,
	FILE_DESCRIPTOR,
	ARGUMENT
};

static const int g_non_terminal_tokens[ARR_NON_TERM_SIZE] = {
	COMMAND,
	STRING,
	RAW_STRING,
	OPTION,
	ARGUMENT,
	ENV_VARIABLE,
	REDIRECTION,
	FILE_DESCRIPTOR
};

static const int g_terminal_tokens[ARR_TERM_SIZE] = {OPERATOR, PIPE};

t_queue				*queue_init(t_token token);
t_queue				*queue_copy(t_queue *origin);
t_queue				*enqueue(t_queue **head, t_token token);
t_queue				*dequeue(t_queue **head);
void				queue_free(t_queue *node);
void				queue_delete(t_queue **head);
t_queue				*lexer(const char *input);

int					is_bash_charset(int c);
int					is_redirect(int c);
int					is_sep(int c);
char				*quote_extract(const char *input, size_t *index);
int					is_escaped_by(const char *s, char *charset);
int					is_quote_closed(const char *s, char quote);
char				*remove_quotes(const char *input, size_t *index);

int					get_argument(t_queue **head,
					const char *input,
					size_t index);
int					get_command(t_queue **head,
					const char *input,
					size_t index);
int					get_env_variable(t_queue **head,
					const char *input,
					size_t index);
int					get_fd(t_queue **head,
					const char *input,
					size_t index);
int					get_operator(t_queue **head, size_t index);
int					get_option(t_queue **head,
					const char *input,
					size_t index);
int					get_pipe(t_queue **head, size_t index);
int					get_redirection(t_queue **head,
					const char *input,
					size_t index);
int					get_string(t_queue **head,
					const char *input,
					size_t index);

int					callback_argument(t_lexer *lex);
int					callback_command(t_lexer *lex);
int					callback_env_variable(t_lexer *lex);
int					callback_fd(t_lexer *lex);
int					callback_operator(t_lexer *lex);
int					callback_option(t_lexer *lex);
int					callback_pipe(t_lexer *lex);
int					callback_redirection(t_lexer *lex);
int					callback_string(t_lexer *lex);
int					callback_default(t_lexer *lex);

typedef int	(*t_callback_lexer)(t_lexer*);

static const t_callback_lexer g_lexer_callbacks[LEXER_CALLBACK_SIZE] = {
	callback_command,
	callback_string,
	callback_option,
	callback_pipe,
	callback_operator,
	callback_env_variable,
	callback_redirection,
	callback_argument,
	callback_fd,
	callback_default
};

#endif
