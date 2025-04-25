echo "enter 1st number:"
read a
echo "enter 2nd number:"
read b
if [ $a -lt $b ];then
	echo "$b is greater"
elif [ $b -eq $a ];then
	echo "equal"
else
	echo "$a is greater"
fi

