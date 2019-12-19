#!/bin/bash
if [ `cat file.txt | wc -l` -ge 10 ]; then sed -n '10 p' file.txt; else echo ""; fi
