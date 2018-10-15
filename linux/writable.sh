#!/bin/bash

FILE="$1"
 
[ $# -eq 0 ] && exit 1
 
if [ -w "$FILE" ] 
then
   echo "Write permission is granted on $FILE"
else
   echo "Write permission is NOT granted on $FILE"
fi
