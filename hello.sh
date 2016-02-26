#!/bin/bash

echo "Enter the username"
read NAME
if [ $NAME = $USER ]; then
    OPTIONS="Hello Quit IP"
    select opt in $OPTIONS; do
	if [ $opt = "Hello" ]; then
	    echo Hello World
	elif [ $opt = "Quit" ]; then
	    echo Quiting
	    exit
	elif [ $opt = "IP" ]; then
	    ifconfig | grep inet
	else
	    clear
	    echo bad option
	fi
    done
fi

echo Operation for non-users
count=1
let count=count+1
echo $count

ifconfig | grep '\b[0-9]\+\.[0-9]\+\.[0-9]\+\.[0-9]\+\b'
