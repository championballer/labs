#!/bin/sh

echo "Please enter number to be checked for prime property: "

read n

current=2

flag=0

while [ $((current*current)) -le $n ]
do
	if (($n % $current == 0 )); then
		flag=1
		break
	fi

	current=$((current+1)) 
done

if [ "$flag" = "1" ]; then
	echo not prime
else echo prime
fi
