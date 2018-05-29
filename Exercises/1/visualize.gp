set datafile separator ';'
set key outside

set xlabel "Time step, s."
set ylabel "T, °C"

filename="T_a.csv"

plot for [col=2:2] filename using col:xtic(1) with lines title columnheader