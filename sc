#!/usr/bin/env bash
#_source

#WARNING: requires xdotool installed!!!

if [[ $1 == "--help" ]]
then
	echo "enters the scripts directory and writes on input stream command \`gedit \$lastEditedScript &\`"
fi

cd ~/scripts

file=''
time="0"
fileBest=''
timeBest="0"
for line in `git ls-files --debug | sed 's/^ *//' | sed 's/ /#/'`
do 
	#echo $line
	if [[ `ls | grep $line` ]]
	then
		file=$line
	fi
	if [[ $line =~ mtime ]]
	then
	echo $line
		time=`echo $line | sed 's/.*: //' | sed 's/:.*//'`
		echo "$file $time"
		if [[ $(( $time>$timeBest )) ]]
		then
			timeBest=$time
			fileBest=$file
		fi
	fi
done

echo $fileBest

#xdotool type "gedit $fileBest &"
#clear
