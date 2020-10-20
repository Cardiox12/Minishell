#!/bin/bash

printf "Welcome to minihell's minitest\n"

printf "compilation:\n"
make
printf "==========================:\n"
printf "basic tests:\n"


function test_command {
printf "ls -l > miniout1\n" | ./minishell &> /dev/null
ls -l > realout1
printf "result test1: \n"

printf "result test1: \n" > test_trace
if diff miniout1 realout2 >> test_trace
then
	printf "test1 : success";
else
	printf "test1 : failed";
fi
}



