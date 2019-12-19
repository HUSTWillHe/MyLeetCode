#!/bin/bash

#cat 192_word_frequency.txt | xargs -n 1 | awk '{
#if($1 in data) 
#	data[$1] += 1
#else 
#	data[$1] = 1
#}
#END {
#	for (str in data)
#		print data[str], str
#}' | sort -rn | awk '{print $2, $1}'

cat words.txt | xargs -n 1 | sort | uniq -c | sort -k1r | awk '{print $2,$1}'
