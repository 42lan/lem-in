# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    repeater.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/30 19:34:26 by amalsago          #+#    #+#              #
#    Updated: 2020/05/30 22:28:04 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear

echo '
    __                     _                                     __           
   / /__  ____ ___        (_)___     ________  ____  ___  ____ _/ /____  _____
  / / _ \/ __ `__ \______/ / __ \   / ___/ _ \/ __ \/ _ \/ __ `/ __/ _ \/ ___/
 / /  __/ / / / / /_____/ / / / /  / /  /  __/ /_/ /  __/ /_/ / /_/  __/ /    
/_/\___/_/ /_/ /_/     /_/_/ /_/  /_/   \___/ .___/\___/\__,_/\__/\___/_/     
                                           /_/  61 6D 61 6C 73 61 67 6F 
'
read -p "Give path to your lem-in binary:       " lemin
read -p "Give path to verifier:                 " verifier
read -p "Give path to generator:                " generator
read -p "How many time you want to repeat test  " nbrep

echo "\nChoose one of the available maps"
options=("flow-one" "flow-ten" "flow-thousand" "big" "big-superposition")

lemin=../lem-in
verifier=../verifier
generator=../maps/generator_mac

refresh_prompt()
{
	tput cuu1
	tput el
	tput cuu1
	tput el
	tput cuu1
	tput el
	tput cuu1
	tput el
}

launch_repeater()
{
	mkdir -p trash
	for i in {1..42};
	do
		$generator --$1 > trash/$i
		tail -n1 trash/$i | awk '{printf("\nRequired moves: %-2d\n", $8)}'
		printf " Lem-in result: "
		$lemin < trash/$i | $verifier
		sleep 1
		refresh_prompt
	done
	rm -rf trash
}

select opt in "${options[@]}"
do
	case $opt in
		"flow-one")
			launch_repeater $opt
			;;
		"flow-ten")
			launch_repeater $opt
			;;
		"flow-thousand")
			launch_repeater $opt
			;;
		"big")
			launch_repeater $opt
			;;
		"big-superposition")
			launch_repeater $opt
			;;
		*) echo "Invalid option $REPLY";;
	esac
done

