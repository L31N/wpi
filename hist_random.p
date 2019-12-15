reset
set title 'Quaternion Misorientation Random'
set xrange[0:360]
set xlabel "Misorientation Angle [°]"
set ylabel "Relative Frequency"
set grid
set style fill transparent solid 0.5 noborder
plot 'hist_random.dat' with boxes
