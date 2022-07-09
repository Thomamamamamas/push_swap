#!/bin/zsh
n=0
while [ $n -lt $1 ]
do
	tmp=$(( ( $RANDOM % $3 ) + $2 ))
		res="$res $tmp"
		n=$(($n+1))
		echo $res
done
