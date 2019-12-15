reset
set title 'Quaternion Misorientation Cubic'
set xrange[0:360]
set xlabel "Misorientation Angle [°]"
set ylabel "Relative Frequency"
set grid
set style fill transparent solid 0.5 noborder
plot 'hist_cube.dat' with boxes
