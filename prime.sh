echo "Enter a number"
read n
p=0
for((i=2;i*i<=n;i++))
do
	if((n%i==0))
		then
			p=1
			break
	fi
done
if [ "$p" -eq 1 ];then
	echo "Not prime"
else
	echo "Prime"
fi

