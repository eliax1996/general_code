#!/bin/bash
i=0

for val in $(cat $1)
do
	i=0
	
	for j in $(seq 1 8)
	do
		echo -n " "
	done
	
	if [ $val -lt 5 ]
	then
		for j in $(seq 1 5)
		do
			echo -n " "
		done
	elif :
	then
		for j in $(seq 1 5)
		do
			echo -n "*"
		done
	fi
	
	while [ $i -lt $val ]
	do
		echo -n "*"
		let i=i+1
	done
	echo
done
echo