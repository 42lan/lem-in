# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    agmt.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 15:05:25 by amalsago          #+#    #+#              #
#    Updated: 2020/06/03 08:55:05 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NC='[0m'
GREY='[1;30m'
RED='[1;31m'
YELLOW='[1;33m'
GREEN='[1;36m'
WHITE='[1;37m'

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
	i=1
	folder=$1
	type=$2
	read -p "How many times perform the test? (default 1 time) "
	[[ -z $REPLY ]] && times=1 || times=$REPLY
	while [[ $i -le $times ]]; do
		printf $GREY"Current file: %s/%d\n"$NC $folder $i
		$generator --$type > $folder/$i
		tail -n1 $folder/$i | awk '{printf("  Required: %d\n", $8)}'
		printf "  Lem-in:   " | tr -d "\n"
		$lemin < $folder/$i | $verifier
		echo
		sleep 1
		if [[ ! $i -eq $times ]]; then
			clear_line 4
		fi
		(( i = i + 1 ))
	done
	clear_line 1
}

declare -a maps=("flow-one" "flow-ten" "flow-thousand" "big" "big-superposition")

function agmt()
{
	header
	make
	if [ -d "trash" ]; then
		echo "Delete trash folder"
		read -p "Do you want to delete it? (y/N) "
		if [[ $REPLY = y ]]; then
			rm -rf trash
		else
			header
			clear_line 1
			echo "Bye bye"
			exit
		fi
	fi
	mkdir trash
	get_executables
	j=1;
	for i in "${maps[@]}"; do
		header
		mkdir trash/$i
		printf $RED"GENERATING $i MAP WITH 1 SEC. LAPS\n\n"$NC
		agmt_helper trash/$i $i
		echo
		if [[ $j -lt ${#maps[@]} ]]; then
			read -p "[1;33mContinue?0"
		fi
		(( j = j + 1 ))
	done
}

lemin=""
verifier=""
generator=""

# Hide terminal cursor
tput civis
agmt
# Show terminal cursor
tput cnorm
