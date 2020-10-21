#! /bin/bash

#set -x
printf "Welcome to minihell's minitest\n"

printf "compilation:\n"
if ! make
then
	printf "\e[38;5;160mcompilation failed\e[0m\n"
	exit 1
fi
printf "==========================:\n"
printf "basic tests:\n"

rm test_trace

function test_command {
	printf "\n=====================\n"
	printf "tested command : %s\n" "$1"
	printf "result test: \n"
	printf "===============\n" >> test_trace
	printf "result test for :     %s\n" "$1">> test_trace
	minicommand=$1
	minicommand+=" > miniout1"
	real_command=$1
	real_command+=" > realout1"
#	printf "minishell's command: %s\n" "$minicommand"
#	printf "eval's command: %s\n" "$real_command"
	if printf "%s\n" "$minicommand" | ./minishell &> /dev/null
	then
		printf "minishell exits with success\n" | tee -a test_trace
	else
		printf "minishell crashes\n" | tee -a test_trace
	fi
	if printf "%s\n" "$real_command" | bash &> /dev/null
	then
		printf "bash exits correctly\n" 
	else
		printf "bash returns an error\n"
	fi	
	if diff miniout1 realout1 >> test_trace
	then
		printf "\e[38;5;40msuccess\e[0m\n" | tee -a test_trace
	else
		printf "\e[38;5;160mfailure\e[0m\n" | tee -a test_trace
		printf "\nminishell's output:\n" >> test_trace
		cat miniout1 >> test_trace
		printf "\neval's output:\n\n" >> test_trace
		cat realout1 >> test_trace
	fi
	printf "===============\n\n" >> test_trace
	printf "%s\n" '-----------------'
	rm miniout1 realout1
}


function test_command_output_redirects {
	printf "\n=====================\n"
	printf "tested command : %s\n" "$1"
	printf "result test: \n"
	printf "===============\n" >> test_trace
	printf "result test for :     %s\n" "$1">> test_trace
	minicommand=$1
	minicommand=${minicommand//output/miniout}
	minicommand+=" > miniout1"
	real_command=$1
	real_command=${real_command//output/realout}
	real_command+=" > realout1"
	printf "minishell's command: %s\n" "$minicommand"
	printf "bash's command: %s\n" "$real_command"
	if printf "%s\n" "$minicommand" | ./minishell &> /dev/null
	then
		printf "minishell exits with success\n" | tee -a test_trace
	else
		printf "minishell crashes\n" | tee -a test_trace
	fi
	if printf "%s\n" "$real_command" | bash &> /dev/null
	then
		printf "bash exits correctly\n" 
	else
		printf "bash returns an error\n"
	fi
	cat miniout2	
	cat realout2	
	if diff miniout1 realout1 >> test_trace && diff miniout2 realout2 >> test_trace && diff miniout3 realout3 >> test_trace
	then
		printf "\e[38;5;40msuccess\e[0m\n" | tee -a test_trace
	else
		printf "\e[38;5;160mfailure\e[0m\n" | tee -a test_trace
		if ! diff miniout1 realout1 &> /dev/null
		then
			printf "\nminishell's output1:\n" >> test_trace
			cat miniout1 >> test_trace
			printf "\nbash's output1:\n" >> test_trace
			cat realout1 >> test_trace
		fi
		if ! diff miniout2 realout2 &> /dev/null
		then
			printf "\nminishell's output2:\n" >> test_trace
			cat miniout2 >> test_trace
			printf "\nbash's output2:\n" >> test_trace
			cat realout2 >> test_trace
		fi
		if ! diff miniout3 realout3 &> /dev/null
		then
			printf "\nminishell's output3:\n" >> test_trace
			cat miniout3 >> test_trace
			printf "\nbash's output3:\n" >> test_trace
			cat realout3 >> test_trace
		fi
	fi
	printf "===============\n\n" >> test_trace
	printf "%s\n" '-----------------'
	rm miniout1 realout1 miniout2 miniout3 realout2 realout3
}

commands=("cat makefile" \
"cat makefile | wc -l" \
"cat makefile < main.c | grep include" \
"cat makefile < main.c | grep include | grep inc < includes/eval.h" \
"cat makefile < main.c | grep include | grep inc < includes/eval.h | wc -l"\
)

#the commands must include 2 and only 2 output redirections, and they must be named output2 and output3
output_commands=("cat makefile > output2 > output3" \
"cat makefile > output2 > output3 | grep include" \
"cat makefile > output2 > output3 < main.c | grep include" \
"cat makefile > output2 > output3 < main.c | grep include < main.c" \
"cat makefile > output2 < main.c | grep include > output3" \
"cat makefile > output2 < main.c | grep include | grep inc < main.c > output3" \
"cat makefile < main.c | grep include > output2 | grep inc < main.c > output3" \
"cat makefile < main.c | grep include | grep inc < main.c > output3 > output2" \
"cat test_files/aaa | grep a | grep b < test_files/ccc > output3 > output2" \
"cat test_files/aaa | grep a > output3 | grep b < test_files/ccc | grep a < test_files/aaa > output2" \
"cat test_files/aaa | grep a > output3 | grep b < test_files/ccc > output2 | grep a < test_files/aaa < test_files/bbb > output2" \
"grep b < test_files/ccc > output2 | grep a < test_files/aaa < test_files/bbb > output2 > output3" \
"echo hello > output2 | grep a < test_files/aaa > output2 > output3" \
"echo hello > output2 > output3" \
)
#printf "%s\n" "cat makefile < main.c | grep include | grep inc < includes/eval.h > miniout1" | ./minishell

#printf "%s\n" "cat makefile < main.c | grep include | grep inc < includes/eval.h | wc" | ./minishell

#test_command "cat makefile < main.c | grep include | grep inc < includes/eval.h"
#eval 'cat makefile < main.c | grep include | grep inc < includes/eval.h'
for command in "${commands[@]}"
	do test_command "${command}"
done

for command in "${output_commands[@]}"
	do test_command_output_redirects "${command}"
done