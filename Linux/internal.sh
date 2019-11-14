#!/bin/sh

echo "Enter file name:"

read file_name

line_count= wc -l $file_name
