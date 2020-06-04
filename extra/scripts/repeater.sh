# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    repeater.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/30 19:34:26 by amalsago          #+#    #+#              #
#    Updated: 2020/05/31 17:23:48 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NC='\033[0m'
GREEN='\033[1;32m'
WHITE='\033[1;37m'

clear
echo "$GREEN
      __                     _                                     __           
     / /__  ____ ___        (_)___     ________  ____  ___  ____ _/ /____  _____
    / / _ \/ __ \`__ \______/ / __ \   / ___/ _ \/ __ \/ _ \/ __ \`/ __/ _ \/ ___/
   / /  __/ / / / / /_____/ / / / /  / /  /  __/ /_/ /  __/ /_/ / /_/  __/ /    
  /_/\___/_/ /_/ /_/     /_/_/ /_/  /_/   \___/ .___/\___/\__,_/\__/\___/_/     
                                             /_/$WHITE 61 6D 61 6C 73 61 67 6F 
  
  
$NC"

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

launch_repeater()
{
	mkdir -p trash
	i=1
	while [[ $i -le $2 ]]; do
		$generator --$1 > trash/$i
		tail -n1 trash/$i | awk '{printf("\nRequired moves: %-2d\n", $8)}'
		printf " Lem-in result: "
		$lemin < trash/$i | $verifier
		sleep 1
		if [[ ! i -eq $2 ]]; then
			clear_line 3
		fi
		(( i = i + 1 ))
	done
	clear_line 4
	rm -rf trash
}

#lemin=./lem-in
#verifier=./verifier
#generator=./generator
get_executables

read -p "How many time you want to repeat test  " nbrep

echo "\nChoose one of the available maps"
options=("flow-one" "flow-ten" "flow-thousand" "big" "big-superposition")
select opt in "${options[@]}"
do
	case $opt in
		"flow-one")
			launch_repeater $opt $nbrep
			;;
		"flow-ten")
			launch_repeater $opt $nbrep
			;;
		"flow-thousand")
			launch_repeater $opt $nbrep
			;;
		"big")
			launch_repeater $opt $nbrep
			;;
		"big-superposition")
			launch_repeater $opt $nbrep
			;;
		*) echo "Invalid option $REPLY";;
	esac
done
