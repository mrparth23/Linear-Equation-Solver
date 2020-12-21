set term pngcairo
set output "Equation curve.png"
set title "Original Curve"
set xlabel "Heights(cm)"
set ylabel "Weights(kg)"
plot 'data.txt' smooth unique with linespoints pt 7 notitle