#!/bin/sh

# Note that there must be no spaces around the "=" sign: VAR=value works; VAR = value
# doesn't work. In the first case, the shell sees the "=" symbol and treats the command 
# as a variable assignment. In the second case, the shell assumes that VAR must be the 
# name of a command and tries to execute it.
# If you think about it, this makes sense - how else could you tell it to run the command
#  VAR with its first argument being "=" and its second argument being "value"? 

# Shoutout to export and source, need to be looked into during revision

echo "What is your name?"
read USER_NAME
echo "Hello $USER_NAME"
echo "I will create you a file called ${USER_NAME}_file"
touch "${USER_NAME}_file"