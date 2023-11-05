reset
set terminal pngcairo size 800,600 enhanced font 'Verdana,12'
set output 'performance_plot.png'

set title "Evolution du temps d'éxecution des Fonctions de Tri"
set xlabel "Dimensions"
set ylabel "Temps d'Éxécution (s)"

# Couleurs pour les courbes
set style line 1 lc rgb '#FF0000' lw 2  # Rouge
set style line 2 lc rgb '#008000' lw 2  # Vert
set style line 3 lc rgb '#0000FF' lw 2  # Bleu
set style line 4 lc rgb '#FFA500' lw 2  # Orange
set style line 5 lc rgb '#800080' lw 2  # Violet
set style line 6 lc rgb '#00FFFF' lw 2  # Cyan
set style line 7 lc rgb '#FF00FF' lw 2  # Magenta
set style line 8 lc rgb '#008080' lw 2  # Teal
set style line 9 lc rgb '#800000' lw 2  # Maroon
set style line 10 lc rgb '#808000' lw 2  # Olive

set key top left
set key box

# Charge les données depuis le fichier data.txt
plot "data.txt" using 1:2 with lines ls 1 title "ShellSort", \
     "data.txt" using 1:3 with lines ls 2 title "Selection", \
     "data.txt" using 1:4 with lines ls 3 title "BubbleSort", \
     "data.txt" using 1:5 with lines ls 4 title "Insertion", \
     "data.txt" using 1:6 with lines ls 5 title "CocktailSort", \
     "data.txt" using 1:7 with lines ls 6 title "CombSort", \
     "data.txt" using 1:8 with lines ls 7 title "OddEvenSort"
