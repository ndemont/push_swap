#!/bin/bash

FILENAME="/tmp/push_swap_tester.sh"
a=0

# ABANDON
#MODE=$1
#
#if [[ $MODE == '' ]]
#then
#	printf "usage:./tester.sh [all | 1 | 2 | 3]"
#	exit
#elif [[ $MODE == "all" ]]
#then
#	printf "all"
#elif [[ $MODE == "1" ]]
#then
#	printf "1"
#
#elif [[ $MODE == "2" ]]
#then
#	printf "2"
#	
#elif [[ $MODE == "3" ]]
#then
#	printf "3"
#fi

for nb_arg in {1..500}
	do
	
	if [[ $nb_arg -le 3 ]]
	then
		LIMIT=3
	elif [[ $nb_arg -le 5 ]]
	then
		LIMIT=12
	elif [[ $nb_arg -le 100 ]]
	then
		LIMIT=700
	elif [[ $nb_arg -le 500 ]]
	then
		LIMIT=5500
	fi
	ARG=`ruby -e "puts (1..$nb_arg).to_a.shuffle.join(' ')"`
	
	for test in {1..20}
	do
		((a++))
		printf "\r$a/10000 testing with limit $LIMIT and args number $nb_arg"
		./push_swap $ARG > ${FILENAME}
		op_nb=`cat ${FILENAME} | wc -l | tr -d ' '`
 		checker_ok=`cat ${FILENAME} | ./checker $ARG`
  	
		if [[ ${op_nb} -gt ${LIMIT} || $checker_ok != "OK" ]]
		then
			printf "\nKO number of operations: $op_nb but limit is: $LIMIT with $nb_arg arguments:\n$ARG\n"
			exit
		fi
	done
done

echo "tests success"
