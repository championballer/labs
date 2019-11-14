#!/bin/sh

echo About to run special variables command

echo Number of variables passed: $#
# echo variable one : $1
# echo variable two : $2
# echo $@
# echo "$@"

if [ "$1" = one ] || [ "$1" = first ]; then
	echo First argument is $1
else 
	echo Second argument is $2
fi

if [ "$1" = one -a  "$1" = first ]; then
	echo First argument is $1
else 
	echo Second argument is $2
fi

if [ "$1" = one -o "$1" = first ]; then
	echo First argument is $1
else 
	echo Second argument is $2
fi

for current in $@; do
	echo current : $current
done
shift

sed 3,6d $1 | echo 
echo $#
# echo variables one post shift : $1
# echo $0

# echo $0: bad option $1 1>&2
# echo $?



