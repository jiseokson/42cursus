#!/bin/bash

N1=$( echo $FT_NBR1 | tr \' 0 | tr \\ 1 | tr \" 2 | tr \? 3 | tr \! 4 )
N2=$( echo $FT_NBR2 | tr "mrdoc" "01234" )
echo "obase=13; ibase=5; $N1 + $N2" | bc | tr "0123456789ABCD" "gtaio luSnemf"
