#!/usr/bin/bash

n1=40
n2=6

echo $(( n1 / n2 ))
echo $(( n1 / n2 ))
echo $(( n1 % n2 ))

expr $n1 + $n2

echo "Enter hex number"
read -r Hex

echo -n "The decimal value of $Hex is: "
echo "obase=10; ibase=16; $Hex" | bc
