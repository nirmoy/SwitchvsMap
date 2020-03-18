set output 'result.png'
set title "Performance of Switch-case vs Map for 1000000 lookup"
set ylabel "Seconds"
set xlabel "Num of iterations"
plot 'data_point.csv' using 1:2 with lines title "map", '' using 1:3 with lines title "switch"

