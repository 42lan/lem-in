# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    agmt.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 15:05:25 by amalsago          #+#    #+#              #
#    Updated: 2020/06/02 19:51:04 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NC='\033[0m'
RED='\033[1;31m'
YELLOW='\033[1;33m'
GREEN='\033[1;36m'
WHITE='\033[1;37m'

clear
function header
{
clear
echo "$GREEN
     __                  _                   ___   ________  _________
    / /__  ____ ___     (_)___              /   | / ____/  |/  /_  __/
   / / _ \/ __ \`__ \___/ / __ \   ______   / /| |/ / __/ /|_/ / / /   
  / /  __/ / / / / /__/ / / / /  /_____/  / ___ / /_/ / /  / / / /    
 /_/\___/_/ /_/ /_/  /_/_/ /_/           /_/  |_\____/_/  /_/ /_/     
                                        $WHITE 61 6D 61 6C 73 61 67 6F 

$NC"
}

function clear_line()
{
	tput cuu $1
	tput el
}

function get_executables()
{
	while [ -z $lemin ]; do
		read -p "Give path to your lem-in binary:       " lemin
		if [ ! -x $lemin ]; then
			clear_line 1
			lemin=""
		fi
	done
	while [ -z $verifier ]; do
		read -p "Give path to verifier:                 " verifier
		if [ ! -x $verifier ]; then
			clear_line 1
			verifier=""
		fi
	done
	while [ -z $generator ]; do
		read -p "Give path to generator:                " generator
		if [ ! -x $generator ]; then
			clear_line 1
			generator=""
		fi
	done
}

function agmt_helper()
{
	folder=$1
	type=$2
	for i in {1..10}; do
		printf "%s/%d\n" $folder $i
		$generator --$type > $folder/$i
		tail -n1 $folder/$i | awk '{printf("  Required: %d\n", $8)}'
		echo "  Lem-in:   " | tr -d "\n"
		$lemin < $folder/$i | $verifier
		echo
	done
}

declare -a maps=("flow-one" "flow-ten" "flow-thousand" "big" "big-superposition")

function agmt()
{
	header
	make
	if [ -d "trash" ]; then
		echo "Delete trash folder"
		exit
	fi
	mkdir trash
	get_executables
	for i in "${maps[@]}"; do
		header
		mkdir trash/$i
		echo $RED"Testing $i\n"$NC
		agmt_helper trash/$i $i
		echo $YELLOW
		read -p "Continue? (hit Enter) "
		echo $NC
	done
}

lemin=""
verifier=""
genarator=""
agmt
