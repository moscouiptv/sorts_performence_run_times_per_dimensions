# Comparaison des méthodes de tri en Python et en C

Ce projet compare les performances de différentes méthodes de tri en utilisant à la fois Python et C. Les méthodes de tri incluent shellSort, selection, bulle, insertion, CocktailSort, combSort et oddEvenSort. Le script en Python mesure le temps d'exécution des méthodes de tri pour différentes dimensions de tableau, tandis que le code C effectue des mesures similaires et enregistre les résultats dans un fichier `data.txt`.

## Prérequis

- **Python** : Assurez-vous d'avoir Python installé sur votre machine.
- **C Compiler** : Vous aurez besoin d'un compilateur C pour exécuter le code C fourni.

## Bibliothèques requises pour Python

- `time`
- `numpy`
- `matplotlib`

Installez les bibliothèques Python nécessaires en utilisant la commande suivante :


## Comment exécuter le script Python

1. Assurez-vous que les bibliothèques requises pour Python sont installées.
2. Exécutez le script Python `tri_methodes.py`.

## Comment exécuter le code C

1. Compilez le fichier C `tri_methodes.c` en utilisant votre compilateur C préféré (par exemple, GCC).
2. Exécutez le fichier compilé.

## Description des fichiers

- `tri_methodes.py` : Script Python pour mesurer et comparer les temps d'exécution des méthodes de tri.
- `tri_methodes.c` : Code C pour mesurer les temps d'exécution des mêmes méthodes de tri.

## Utilisation

1. Le script Python génère un graphique montrant les temps d'exécution en fonction de la dimension du tableau pour chaque méthode de tri.
2. Le code C enregistre les temps d'exécution dans un fichier `data.txt` avec des colonnes distinctes pour chaque méthode de tri.

### Remarque sur le code C

- Assurez-vous d'avoir un compilateur C installé pour exécuter le code C fourni.
- Le fichier C génère un fichier `data.txt` contenant les temps d'exécution pour les différentes méthodes de tri en fonction de la dimension du tableau.
