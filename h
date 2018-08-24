#!/usr/bin/env bash
#_source


if [[ $1 == "--help" ]]
then
	echo "script to search history for last use of command that matches given pattern and executes it right away
type: 				h \$pattern
to see first n found commands:	h -l\$n \$pattern"
	exit
fi

#dodać opcję bez automatycznego zatwierdzania

pattern=$1
counters=1
if [[ (${1::1} == "-") && (`echo $1 | grep -E "l[0-9]+"`) ]]
then
	counters=`echo $1 | sed 's/-.*l//'`
	to_cut=`echo $counters | sed -E 's/^[0-9]+//'`
	if [[ ! -z $to_cut ]]
	then
		counters=`echo $counters | sed "s/$to_cut//"`
	fi
	pattern=$2
fi

i=`history | wc -l`
comm=''
for x in `seq $i -1 1`
do
	line=`history | sed -n "$x p" | cut -d" " -f4-`
	i=$((x++))
	if [[ `echo $line | grep $pattern` ]]
	then
		if [[ $line =~ (h .*) ]]
		then
			continue
		fi
		#echo "found: $line"
		comm="$comm$line;;"
		if [[ `echo $comm | sed 's/;;/\n/g' | wc -l` == $(($counters+1)) ]]
		then
			break
		fi
	fi
done

if [[ $counters == "1" ]]
then
	comm=`echo $comm | sed 's/;//g'`
	$comm &> /dev/null
else
	echo $comm | sed 's/;;$//' | sed 's/;;/\n/g'
fi
if [[ $? == '127' ]]					#when a command is an alias
then			#hmm to nie uwzględnia sytuacji, gdy alias ma coś przysłaniać...no ale co? Mam je przeszukiwać za każdym pojedynczym razem?
	al=`echo $comm | cut -d" " -f1`
	replace=`cat ~/.bashrc | grep "alias $al=" | sed 's/alias .*=//' | sed 's/\x27//g'`
	comm=`echo $comm | sed "s|$al|$replace|"`
	echo $comm
	$comm
fi

			#2) w razie komendy z gwiazdką grep przeszukuje też wówczas będące pod gwiazdką słowa i ostatecznie wywołuje `command *` w danej lokalizacji
