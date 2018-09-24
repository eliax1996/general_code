#!/bin/bash


#inizializzo variabili
flag=1

result=0

for val in $(cat $1)
do
	if [ $flag -eq 1 ]
	then
		let result=result+3*val*val
	elif [ $flag -eq 2 ]
	then
		let result=result+4*val
	elif [ $flag -eq 3 ]
	then
		flag=0
		let result=result+5*val
		echo "risultato $result"
		result=0
	fi
let flag=flag+1
done