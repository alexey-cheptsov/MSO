set datafile separator ';'
set key outside

set xlabel "Time step, s."
set ylabel "T, °C"

filenames="T_a.csv T_b.csv"

plot for [file in filenames] for [col=2:2] file using col:xtic(log($1)) with lines title columnheader
# plot for [col=2:2] "T_b.csv" using col:xtic(1) with lines title columnheader