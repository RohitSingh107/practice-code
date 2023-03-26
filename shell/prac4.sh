#!/bin/bash


echo "Enter the number"
read -r n

echo "Number is $n"


for i in {a..d}
do
  echo "char is $i"
done

i=1

while [ $i -le $n ]
do
  echo "Number is $i"
  i=$(( i + 1 ))
done

for i in $(seq 1 2 20)
do
   echo "Welcome $i times"
done

for((i=10; i<=50; i=$((i+10))))
do
  echo "Num is $i"
done

echo "Enter some number"
read a

# if [ "$(expr $a % 2)" == 1 ]
if [ $(( a % 2 )) == 1 ]
then
  echo "Number is Odd"
else
  echo "Number is Even"
fi

if [ $a -gt 0 ]
then
  echo "Number is positive"
elif [ "$a" -lt 0 ]
then
  echo "Number is negative"
else
  echo "Number is zero"
fi

#!/bin/bash
for file in /etc/*
do
    echo "$file"
    if [ "${file}" == "/etc/passwd" ]
    then
        countNameservers=$(grep -c nixbld "$file")
        echo "Total  ${countNameservers} nixbld defined in ${file}"
        break
    fi
done
