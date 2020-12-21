set term pngcairo
set output "Original curve.png"
set title "Original Curve"
set xlabel "Heights(cm)"
set ylabel "Weights(kg)"
plot 'input.txt' smooth unique with linespoints pt 7 notitle 