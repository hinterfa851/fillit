#!/bin/bash

LOGS=./logs.txt
VALID=../maps/valid/*
INVALID=../maps/invalid/*

{ echo -e 'NORMINETTE\n'

//norminette -R CheckForbiddenSourceHeader

echo -e 'MAKE TEST\n'

//make
echo -e '\n'

echo -e 'VALID MAPS CHECKING\n'

for file in $VALID
do
	echo $(basename $file)
	./fill $file
	echo -e '\n>>>>>>>>>>>>>>>>>\n'
done

echo -e 'INVALID MAPS CHECKING\n'

for file in $INVALID
do
	echo $(basename $file)
	./fill $file
	echo -e '\n>>>>>>>>>>>>>>>>>\n'
done } > $LOGS 2>&1

echo -e 'END TESTS\ncheck logs.txt for results'
