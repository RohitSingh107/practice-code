#!/bin/sh
echo "Enter the value of n: "
read N

i=1
sum=0

while [ $i -le $N ]
do
  echo "Enter the $i  number:"
  read num               #get number
  sum=$((sum + num))     #sum+=num
  i=$((i + 1))
done

avg=$(echo $sum / $N | bc -l)

echo "The Average is $avg"
