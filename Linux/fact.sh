#!/bin/sh

echo "Enter number to find factorial for:"

read n

current=1
product=1

while [ "$current" -le "$n" ]
do
	product=$((product*current))
	current=$((current+1))
done

echo "The factorial for $n : $product"