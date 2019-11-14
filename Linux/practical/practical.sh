#!/bin/sh


find_replace()
{
	sed "s/$1/hello/g" $2 | tee tmp
	mv tmp $2
}

check() {

	re='^[0-9]+$'
	if ! [[ $1 =~ $re ]] ; then
   		echo "String"
	else 
		echo "Number"
	fi
}
 
check 12
check hello
check h12o
find_replace practical sample.txt

