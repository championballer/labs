echo "List of Files which have Read, Write and Execute Permissions in Current Directory"

read=0
write=0
exe=0

for file in *
do
read=0
write=0
exe=0
if [ -r $file ]
	then 
	read=1
fi
if [ -w $file ]
	then
	write=1
fi
if [ -x $file ]
	then
	exe=1
fi

echo "$file r:$read w:$write x:$exe"  


done
