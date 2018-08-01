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
for x in `seq $i -1 1`
do
	comm=`history | sed -n "$x p" | cut -d" " -f4-`
	i=$((x++))
	if [[ `echo $comm | grep $pattern` ]]
	then
		if [[ $comm =~ (h .*) ]]
		then
			continue
		fi
		break
	fi
done

echo $comm
$comm &> /dev/null
if [[ $? == '127' ]]					#when a word is an alias
then
	al=`echo $comm | cut -d" " -f1`
	replace=`cat ~/.bashrc | grep "alias $al=" | sed 's/alias .*=//' | sed 's/\x27//g'`
	echo $replace
	#replace=[$replace]
	#echo $replace
	#comm=`echo $comm | sed "s/$al/$replace/"`
	comm=`echo $comm | sed "s|$al|$replace|"`
	echo $comm	
	#bash ~/scripts/mem ciastkownia	
	$comm

fi

			#1) nie działają aliasy!!!
			#2) w razie komendy z gwiazdką grep przeszukuje też wówczas będące pod gwiazdką słowa i ostatecznie wywołuje `command *` w danej lokalizacji
