echo enter the file name
read first
echo enter the second file name
read second
if [ -e $first ]
then
if [ -e $second ]
then
cat $first>>$second
else
cat $first>$second
fi
fi