#!/usr/bin/env bash
#_source


if [[ -z $1 ]]
then
	echo "script to search history for last use of command that matches given pattern and executes it right away
type: 		h \$pattern"
	exit
fi


pattern=$1
i=`history | wc -l`

for x in `seq 1 $i`
do
	i=$(($i-1))				#na starcie żeby nie zwracało od razu komendy wywołującej(h $pattern)
	comm=`history | sed -n "$i p" | cut -d" " -f4-`
	if [[ `echo $comm | grep $pattern` ]]
	then
		break
		#if [[ $comm=="h $pattern" ]] 	#alternatywa na dekrementację $i na starcie-nie złapie też poprzednich wywołań h $pattern
		#then
		#	continue
		#fi
		#break
	fi
done

echo $comm
`$comm`			#coś z tym nie do końca działa, niby komenda jest poprawna, a jednak się pokazują ciągle jakieś dziwne ciężkie do określenia błędy...
