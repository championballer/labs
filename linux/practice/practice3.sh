#!/bin/sh

# echo Please enter the name of the file to check with extension:
# read filename

# if [ -w "$filename" -a -r "$filename" -o -x '$filename' ]; then
# 	echo Writable
# else 
# 	echo Not Writable
# fi

# for current in *;do
# 	if [ -w "$current" ];then
# 		echo $current has write permission
# 	fi
# 	if [ -r "$current" ];then
# 		echo $current has read permission
# 	fi
# 	if [ -x "$current" ];then
# 		echo $current has execute permission
# 	fi
# done

echo Please enter the word to delete for
read word 

for current in $@;do
	sed -i '' "/$word/d" $current
	
done
