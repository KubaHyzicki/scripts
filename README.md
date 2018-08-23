My bash scripts with a wide range of usabilities



accesGain, STATUS=FEATURE

Description:
gives all permitions and ownership of all files in directiry
optionally gives them also to files in subdirectories-type: accesgain -R
for only chmod +x on all files type(non sudo): accesgain -x"



alarm, STATUS=FEATURE

Description:
Counts down and launches the alarm tune
type: alarm \$secsAmount"



asleep, STATUS=FEATURE

Description:
Counts down and sets machine to sleep
type: asleep \$minuteAmount"



callEnd, STATUS=FEATURE

Description:
just simple print picture that announces the end of previous comand
type: \$currentlyExecutingCommand && callend
or: \$currentlyExecutingCommand; callend"



capsManualUpload, STATUS=SUSPENDED

Description:
copy exel label to \$file and type capsmanualupload \$file, you'll get divided jsons to upload
WARNING: requires jq and curl installed!!!"



cb, STATUS=WORKING

Description:
script copying input to clipboard
WARNING: requires xdotool installed!!!
to copy args type: cb \$arg1 \$arg2...
to copy file insides type: cb -f \$fileName"



cd, STATUS=NOTWORKING

Description:
overwrites cd and adding handler of _notFullDirNames_



changeLines, STATUS=WORKING

Description:
script changes lines in file with given pattern
usage: 1)finds lines by \$pattern
2)changes in each line
...\$preffix[oldVal]\$suffix... -> ...\$prefix\$newVal\$suffix...
It also creates a copy of last changed file, logs from
changes(not only lastest) and allows them to use it to revert
deletelines -c;for file in lsd \$fileNamePattern/lsd -f \$pattern/[oba na pipie];do changelines -al \$pattern \$prefix \$newVal \$suffix \$file \$addedLine;done;deletelines -s
to change lines type: changelines \$pattern \$prefix \$newVal \$suffix \$file
to revert changes from log file: changelines -r
to not overwrite log file type: changelines -l ...
to just display(show) logs file: changelines -s
to clear logs and backup file: changelines -c
to add line if pattern didnt fouded changelines -a ... \$addedLine(as 7th arg)"



countDown, STATUS=WORKING

Description:
simply counts down displaying numbers
type: countDown \$secondsAmount"



crontabQuick, STATUS=NOTWORKING

Description:
was supposed to quickly set and delete crontab jobs NOT FINISHED!!!



deleteLines, STATUS=WORKING

Description:
script deletes lines in file with given pattern
BUT! It also creates a copy of last changed file, logs from
changes(not only lastest) and allows them to use it to revert
###deletelines -c;for x in lsd \$fileNamePattern/lsd -f \$pattern;do deletelines -l \$pattern \$file;done;deletelines -s###
to delete lines type: deletelines \$pattern \$file
to revert changes from log file: deletelines -r
to not overwrite log file type: deletelines -l \$pattern \$file
to just display(show) logs file: deletelines -s
to clear logs and backup file: deletelines -c"



docRun, STATUS=WORKING

Description:
runs container in dir
type container name or skip it and its name will equals directory name"



dockeringAll, STATUS=FEATURE

Description:
runs all containers in dir and subdirs in separate terminals(nginx postponed to be the last if apears)



ftd, STATUS=FEATURE

Description:
Displays input (for now python only!)files functions in a tree of dependence-which does call the other
WARNING: requires tree installed!!!
type: functreedisp
to use on specyfic file: functreedisp \$file.py
to display imports too: functreedisp -i \$file.py"



h, STATUS=FEATURE

Description:
script to search history for last use of command that matches given pattern and executes it right away
type: h \$pattern"



hostCon, STATUS=

Description:
Connects to first host matching pattern from list kept in .hosts
to see all kept hosts type: hostcon
to connect to host: hostcon \$pattern
WARNING: requires xdotool installed!!!"



initFlask, STATUS=WORKING

Description:
script inits basic flask app setup
type: initflask \$appName
or for base name (\"app\"): initflask
then to start app just type: run"



initTest, STATUS=WORKING

Description:
creates templates of all script files in dir(for now only for .py[pytest])



lsd, STATUS=FEATURE

Description:
script to search recursively in the current directory for files or fileses insides that matches given pattern
type: lsd \$pattern_to_look_for
or when searching files insides: lsd -f \$pattern
exposing files if dir founded: lsd -d \$pattern
to use !THE_HARD_REGEX_MODE!: lsd -E \$pattern
to not ingore case: lsd -C \$pattern
searching in input files: lsd -if \$pattern \$file1 \$file2...
----------
also worth to try like: cat \$(lsd -f/d \$pattern) | less
to see all files insides and easly search with \"/\" for multiple occurrence
or: lsd -if \$inFilePattern \`lsd \$nameFilePattern\` #or other similar searches in \`\` quotes
to research only listed in args files founded by other command"



massiveEdit, STATUS=NOTWORKING

Description:
ciastko



mem, STATUS=WORKING

Description:
script acting like an additional cache
to see last input type: mem
to see n inputs type: mem -\$n
to write to memory: mem \$your_input
to clear cache: mem -c
to see all cache: mem -a/all
to operate on second like more important cache type: mem -h"



netCheck, STATUS=SUSPENDED

Description:
scripts checks net connection and saves logs-actually it is create to be being runned from jenkins job



netCheckV2, STATUS=SUSPENDED

Description:
checkNet v2-both just experimental



rdmUpload, STATUS=WORKING

Description:
automaticly creates README.md file structure using --help messeges from scripts and .status file
type: rdmupload"



rm, STATUS=INPROGRESS

Description:
Overwrites rm command with copying dirs/files to backup folder(cleans automaticly after exceeding amount of parametrised backup files



run, STATUS=UNKNOWN

Description:
Search for file you would like to execute in current dir and runs it with given arguments
just type: run \$arg1 \$arg2..."



runas, STATUS=SUSPENDED

Description:
script made for compiling and running assembler file and linking slave programs in specified dir
type(...gdzieś miałem instrukcję więc nie chce mi się jej pisać, później wkleję...)"



sc, STATUS=WORKING

Description:
enters the scripts directory and writes on input stream command \`gedit \$lastEditedScript &\`
WARNING: requires xdotool installed!!!"



scSt, STATUS=WORKING

Description:
script to menage other scripts statuses-there are so many of them that I decided to creare for them sth like base so that
I would know what and where to do whether I actually do or do not want to at the moment, avalible statuses:
INPROGRESS,IDEA,FEATURE,NOTWORKING,UNKNOWN,WORKING,SUSPENDED
to display statuses: scSt
to display one: scst \$file
to display all: scst -a
to not to display comments: scSt -n
to change status type: scSt \$file \$status
to edit comment: scSt -c \$file
to match only exact word: scst -w \$file..."



scrAdd, STATUS=WORKING

Description:
adds all new scripts from ~/scripts/ directory to ~/.bashrc as aliases(script name in lower cases)
basicly if at second line of the script is \"\#_source\" it adds scripts as source"



session, STATUS=WORKING

Description:
runs in google-chrome all links from target file(format one linke per line)
type: session \$filename
for incognito mode: session \$filename -i"



sorter, STATUS=SUSPENDED

Description:
WARNING-Do not use in main dir!!! (lot of work after messing up)
parameters:
-b base(sort by days)
folder names-p path
-h/d/m/y date specified/range(format similar to \`date\`)"



stream, STATUS=FEATURE

Description:
easy stream between virtual and main system(set your stream localisation to .config as \$STREAM)
type for output: stream
or: stream -r
type for input stream \$args"



svnUpdate, STATUS=FEATURE

Description:
ciastko



undockerAll, STATUS=WORKING

Description:
stops containers: undockerall
removes containers: undockerall -c
removes images: undockerall -i"
