#!/bin/bash

exec &>>/var/log/dump-mysql.log

echo "dump-database.sh start"

user="root"
dataBase="classicmodels"
time="$(date +%Y-%m-%d-%H-%M-%S)"

dumpLocation="/home/user/Documents/TDdata/dump/"
dumpName="dump_${dataBase}_${time}"
dumpExtension=".sql"

psw="$(cat /usr/bin/.sqlEncryptedPassword.txt | openssl enc -aes-256-cbc -md sha512 -a -d -pbkdf2 -iter 100000 -salt -pass pass:'sql#encrypted!password')"


mysqldump -u $user -p$psw $dataBase > ${dumpLocation}${dumpName}${dumpExtension}

error=$?

if [ $error!=0 ]; then
	echo "${dataBase} dump successful to ${dumpName}${dumpExtension}"
else 
	echo "error $error : dump fail"
fi


bzip2 ${dumpLocation}${dumpName}${dumpExtension}

error=$?

if [ $error!=0 ]; then
	echo "${dumpName}${dumpExtension} compress successful"
else 
	echo "error $error : compression fail"
fi


nbrFilesRm=$(ls $dumpLocation*$dumpExtension.bz2  | wc -l)-5

if [ $error!=0 ]; then
	for ((c=0; c<$nbrFilesRm; c++)); do
			rmFile=$(ls -t $dumpLocation | tail -1)
			rm $dumpLocation$rmFile
			echo "deleting $rmFile"
	done

	error=$?

		if [ $error!=0 ]; then
			echo "keep last 5 files successful"
		else 
			echo "error $error : files removal fail"
		fi
fi

echo "dump-database.sh end"