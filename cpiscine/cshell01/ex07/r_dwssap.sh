#!/bin/bash
cat /etc/passwd | grep -v "^#" | awk '{if (NR % 2 == 0) print}' | cut -d ':' -f 1 | rev | sort -r | awk -v lo=$FT_LINE1 -v hi=$FT_LINE2 '{if (lo <= NR && NR <= hi) print}' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./' | tr -d '\n'
