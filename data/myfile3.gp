set term pngcairo
set output "New curve.png"
set title "Original Curve"
set xlabel "Heights(cm)"
set ylabel "Weights(kg)"
plot 'data2.txt' smooth unique with linespoints pt 7 notitle 