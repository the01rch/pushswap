#!/bin/bash

nb=$1

generate_random_integers_list() {
    local length=$1
    local random_integers_str=$(shuf -i 1-1000 -n $length | tr '\n' ' ')
    echo $random_integers_str
}

execute_program() {
	local list=$(generate_random_integers_list $nb)
	echo "actions for $nb:"
	exec /home/rr/Documents/School/pushswap/push_swap $list | wc -l
}

execute_program
