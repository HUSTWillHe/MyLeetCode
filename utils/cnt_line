#!/bin/bash
cd `dirname $0`
cd ../solutions/
files=$(ls [0-9]*)
sum=0
for file in ${files}
do
	lines=`eval cat ${file} | wc -l`
	sum=$[sum+lines]
done
echo "All solutions has ${sum} lines."
