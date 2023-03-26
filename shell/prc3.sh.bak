#!/usr/bin/env bash
if [[ $(expr "$1" % 3) == 0 ]] && [[ $(expr "$1" % 5) == 0 ]] && [[ $(expr "$1" % 7) == 0 ]]
	then
		result=PlingPlangPlong
	elif [ $(expr "$1" % 3) == 0 ] && [ $(expr "$1" % 5) == 0 ]
	then
		result=PlingPlang
	elif [ $(expr $1 % 3) == 0 ] && [ $(expr $1 % 7) == 0 ]
	then
		result=PlingPlong
	elif [ $(expr $1 % 5) == 0 ] && [ $(expr $1 % 7) == 0 ]
	then 
		result=PlangPlong
	elif [ $(expr $1 % 3) == 0 ]
	then 
		result=Plang
	elif [ $(expr $1 % 5) == 0 ]
	then
		result=Plang
	elif [ $(expr $1 % 7) == 0 ]
	then
		result=Plong
	else
		result=$1
	echo $result
	fi
