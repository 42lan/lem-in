# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    agmt.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 15:05:25 by amalsago          #+#    #+#              #
#    Updated: 2020/05/23 18:01:34 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear

osname="$(uname -s)"
case "${osname}" in
    Linux*)
		machine=Linux
		genarator=../maps/generator_linux
		;;
    Darwin*)
		machine=Mac
		genarator=../maps/generator_mac
		;;
    *)
		machine="UNKNOWN:${osname}"
		exit 42
esac
echo "You are running on ${machine}"

declare -a maps=("--flow-one" "--flow-ten" "--flow-thousand" "--big" "--big-superposition")

for i in "${maps[@]}"
do
	echo ${i}
	for j in {1..10}
	do
		${genarator} ${i} > map
		../lem-in < map
		tail -n1 map | awk '{print $8}'
		read
		echo
	done
done
rm map
