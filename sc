#!/usr/bin/env bash
#_source

#WARNING: requires xdotool installed!!!

if [[ $1 == "--help" ]]
then
	echo "enters the scripts directory and writes on input stream command \`gedit \$lastEditedScript &\`
WARNING: requires xdotool installed!!!"
	exit
fi

cd ~/scripts

time="0"
fileBest=''
timeBest="0"
for file in `git ls-files | sed '/\..*/d'`
do
	time=`stat $file | grep Modify | sed 's/Modify: //' | sed 's/:..\..*//' | sed 's/[- :]//g'`
	if [[ $time -ge $timeBest ]]
	then
		timeBest=$time
		fileBest=$file
	fi
done

shebang=`cat $fileBest | head -1`
if [[ `echo $shebang | grep 'bash'` ]]; then
	xdotool type "gedit $fileBest &"
elif [[ `echo $shebang | grep 'python'` ]]; then
	xdotool type "pycharm-community $fileBest &"
else
	xdotool type "gedit $fileBest &"
fi

clear
echo "Your branch is: `git branch | grep -E '^\*'`"