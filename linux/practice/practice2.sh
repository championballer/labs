#!/bin/sh

fact()
{
	product=1
	index=1

	while [ $index -le $1 ]; do
		product=$(( $product*$index ))
		index=$(( $index+1 ))
	done

	echo $product

}

natural()
{
	index=1

	while [ $index -le $1 ]; do
		echo $index
		index=$(( $index+1 ))
	done
}

echo Enter first number
read var1 
echo Enter second number
read var2 

fact $var1
natural $var2
echo $product
var3=$(( $var1 + $var2 ))
var4=$(( $var1 * $var2 ))
var5=$(( $var1 ** $var2 ))


