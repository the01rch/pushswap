#!/bin/bash

generate_random_integers_list() {
    local length=$1
    local random_integers_str=$(shuf -i 1-1000 -n $length | tr '\n' ' ')
    echo $random_integers_str
}

for i in $(seq 2 500); do
	list=$(generate_random_integers_list $i)
	echo "List of $i integers: "
	echo $list > list.txt
	result=$(./push_swap "$list" | ./checker_linux "$list")
	echo $result

	if [[ $result == "KO" ]]; then
		echo "Checker returned KO. with this list"
		break
	fi
done
