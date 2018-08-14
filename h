#!/usr/bin/env bash
#_source


if [[ $1 == "--help" ]]
then
	echo "script to search history for last use of command that matches given pattern and executes it right away
type: 		h \$pattern"
	exit
fi

#dodać opcję bez automatycznego zatwierdzania
#dodać opcję wyświetlania pierwszych x komend pasujących do wzorca

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
if [[ $? == '127' ]]					#when a command is an alias
then			#hmm to nie uwzględnia sytuacji, gdy alias ma coś przysłaniać...no ale co? Mam je przeszukiwać za każdym pojedynczym razem?
	al=`echo $comm | cut -d" " -f1`
	replace=`cat ~/.bashrc | grep "alias $al=" | sed 's/alias .*=//' | sed 's/\x27//g'`
	comm=`echo $comm | sed "s|$al|$replace|"`
	echo $comm
	$comm
fi

			#2) w razie komendy z gwiazdką grep przeszukuje też wówczas będące pod gwiazdką słowa i ostatecznie wywołuje `command *` w danej lokalizacji
