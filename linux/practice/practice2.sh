#!/bin/sh

echo Enter first number
read var1 
echo Enter second number
read var2 

echo $var1

calc=$(echo 2.3 4.6 | awk '{ printf "%f", $1 + $2 }')

echo $calc

