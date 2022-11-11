#!/usr/bin/bash

echo "Enter 1st string"
read -r st1

echo "Enter 2nd string"
read -r st2

if [ "$st1" == "$st2" ]
then
  echo "Strings match"
elif [ "$st1" \< "$st2" ]; then
  echo "$st1 is smaller than $st2"
else
  echo "$st1 is bigger than $st2"
fi

c=$st1$st2

echo "Concatination: $c"

echo "Capitalize First ${st1^}"
echo "Capitalize if l ${st1^l}"
echo "Uppercase ${st1^^}"
