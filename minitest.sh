#!/bin/bash

set -x
printf "Welcome to minihell's minitest\n"

printf "compilation:\n"
make
printf "==========================:\n"
printf "basic tests:\n"

rm test_trace

function test_command {
	printf "\n=====================\n"
	printf "tested command : %s\n" "$1"
	printf "result test: \n"
	printf "===============\n" >> test_trace
	printf "result test for :     %s\n" "$1">> test_trace
	rm miniout1 realout1
	minicommand=$1
#	minicommand+=" > miniout1"
	real_command=$1
#	real_command+=" > realout1"
	printf "minishell's command: %s\n" "$minicommand"
	printf "eval's command: %s\n" "$real_command"
	if printf "%s\n" "$minicommand" | ./minishell &> /dev/null
	then
		printf "minishell exits with success\n" | tee -a test_trace
	else
		printf "minishell crashes\n" | tee -a test_trace
	fi
	if eval "$real_command" #&> /dev/null
	then
		printf "eval exits correctly\n" 
	else
		printf "eval crashes\n"
	fi	
	if diff miniout1 realout1 >> test_trace
	then
		printf "success\n" | tee -a test_trace
	else
		printf "failed\n" | tee -a test_trace
		printf "\nminishell's output:\n" >> test_trace
		cat miniout1 >> test_trace
		printf "\neval's output:\n\n" >> test_trace
		cat realout1 >> test_trace
	fi
	printf "===============\n\n" >> test_trace
	printf "%s\n" '-----------------'
}

commands=("cat makefile" \
"cat makefile | wc -l" \
"cat makefile < main.c | grep include" \
"cat makefile < main.c | grep include | grep inc < includes/eval.h" \
"cat makefile < main.c | grep include | grep inc < includes/eval.h | wc -l")

#printf "%s\n" "cat makefile < main.c | grep include | grep inc < includes/eval.h > miniout1" | ./minishell

#printf "%s\n" "cat makefile < main.c | grep include | grep inc < includes/eval.h | wc" | ./minishell

test_command "cat makefile < main.c | grep include | grep inc < includes/eval.h"
eval 'cat makefile < main.c | grep include | grep inc < includes/eval.h'
#for command in "${commands[@]}"
#	do test_command "${command}"
#done