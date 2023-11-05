import time
import numpy as np
import matplotlib.pyplot as plt

max_methods = 4  # Trois méthodes de tri : shellSort, selection, insertion
max_dimensions = 10  # De 1000 à 10000 par incréments de 1000

matrix = np.zeros((max_methods, max_dimensions))
# matrix = [[ 0 for i in range(max_dimensions) ] for j  in range(max_methods) ]


def get_tableau(dim):
    return list(range(dim - 1, -1, -1))


def shellSort(arr):
    start_time = time.time()
    n = len(arr)
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            temp = arr[i]
            j = i
            while j >= interval and arr[j - interval] > temp:
                arr[j] = arr[j - interval]
                j -= interval
            arr[j] = temp
        interval //= 2
    end_time = time.time()
    t = end_time - start_time
    return t


def selection(arr):
    start_time = time.time()
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    end_time = time.time()
    t = end_time - start_time
    return t


def insertion(arr):
    start_time = time.time()
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    end_time = time.time()
    t = end_time - start_time
    return t


def bulle(liste):
    start_time = time.time()
    n = len(liste)
    while n != 0:
        for i in range(n - 1):
            if liste[i] > liste[i + 1]:
                liste[i], liste[i + 1] = liste[i + 1], liste[i]
        n -= 1
    end_time = time.time()
    t = end_time - start_time
    return t


# Remplir la matrice avec les temps d'exécution
for i in range(max_methods):
    if i == 0:
        sorting_function = shellSort
        method_name = "shellSort"
    elif i == 1:
        sorting_function = selection
        method_name = "selection"
    elif i == 2:
        sorting_function = bulle
        method_name = "bulle"
    elif i == 3:
        sorting_function = insertion
        method_name = "insertion"

    for j in range(1,max_dimensions+1):
        dimension = j * 1000
        tableau = get_tableau(dimension)
        execution_time = sorting_function(tableau.copy())
        matrix[i, j-1] = execution_time

print(matrix)



# Tracer le graphe

plt.plot(range(1000, 10001, 1000), matrix[0], label="shellSort")
plt.plot(range(1000, 10001, 1000), matrix[1], label="selection")
plt.plot(range(1000, 10001, 1000), matrix[2], label="bulle")
plt.plot(range(1000, 10001, 1000), matrix[3], label="insertion")

plt.xlabel("Dimension du tableau")
plt.ylabel("Temps d'exécution (secondes)")
plt.legend()
plt.title(
    "Temps d'exécution des fonctions de tri en fonction de la dimension du tableau"
)
plt.show()


