#!/bin/sh

echo Please enter the first file name
read file1
echo Please enter the second file name
read file2

if [ -e file2 -a -f file2 ];then
	cat $file1>>$file2
else 
	cat $file1>$file2
fi
