#!/bin/zsh
n=0
nb_array=()
if [[ $2 == '' ]]; then
	min=0
else
	min=$2
fi
if [[ $3 == '' ]]; then
	max=2147483647
else
	max=$3
fi
while [ $n -lt $1 ]
do
	tmp=$(( ( $RANDOM % $max ) + $min ))
	if [[ ! " ${nb_array[*]} " =~ " ${tmp} " ]]; then
		nb_array+=($tmp)
		res="$res $tmp"
		n=$(($n+1))
	fi
done
echo $res
