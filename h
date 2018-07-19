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

if 

echo $comm
if [[ `$comm 2> | grep ': command not found'` ]]
then
	al=`echo $comm | cut -d" " -f1`
	cat ~/.bashrc | grep "alias =

			#1) nie działają aliasy!!!
			#2) w razie komendy z gwiazdką grep przeszukuje też wówczas będące pod gwiazdką słowa i ostatecznie wywołuje `command *` w danej lokalizacji
