#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_METHODS 7
#define MAX_DIMENSIONS 10

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

double bubble(int arr[], int n);
double insertion(int arr[], int n);
double selection(int arr[], int n);
double shellSort(int arr[], int n);
double CocktailSort(int arr[], int n);
double combSort(int arr[], int n);
double oddEvenSort(int arr[], int n);

double CocktailSort(int arr[], int n)
{
    clock_t start_time, end_time;
    start_time = clock();

    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i <= n - 2; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
    } while (swapped);

    end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

double combSort(int arr[], int n)
{
    clock_t start_time, end_time;
    start_time = clock();

    int gap = n;
    int swapped;
    do
    {
        gap = getNextGap(gap);
        swapped = 0;

        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
    } while (gap != 1 || swapped);

    end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

double oddEvenSort(int arr[], int n)
{
    clock_t start_time, end_time;
    start_time = clock();

    int isSorted = 0;

    while (!isSorted)
    {
        isSorted = 1;

        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = 0;
            }
        }

        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = 0;
            }
        }
    }

    end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

double shellSort(int arr[], int n)
{
    clock_t start_time, end_time;
    start_time = clock();

    int interval = n / 2;
    while (interval > 0)
    {
        for (int i = interval; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= interval && arr[j - interval] > temp)
            {
                arr[j] = arr[j - interval];
                j -= interval;
            }
            arr[j] = temp;
        }
        interval /= 2;
    }

    end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

double selection(int arr[], int n)
{
    clock_t start_time, end_time;
    start_time = clock();

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

double insertion(int arr[], int n)
{
    clock_t start_time, end_time;
    start_time = clock();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

double bubble(int arr[], int n)
{
    clock_t start_time, end_time;
    start_time = clock();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

int main()
{
    int max_dimensions = 10;
    int dimensions[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

    double matrix[MAX_METHODS][MAX_DIMENSIONS];

    double (*sorting_function)(int[], int);

    for (int i = 0; i < MAX_METHODS; i++)
    {
        if (i == 0)
        {
            sorting_function = shellSort;
        }
        else if (i == 1)
        {
            sorting_function = selection;
        }
        else if (i == 2)
        {
            sorting_function = bubble;
        }
        else if (i == 3)
        {
            sorting_function = insertion;
        }
        else if (i == 4)
        {
            sorting_function = CocktailSort;
        }
        else if (i == 5)
        {
            sorting_function = combSort;
        }
        else if (i == 6)
        {
            sorting_function = oddEvenSort;
        }

        for (int j = 0; j < max_dimensions; j++)
        {
            int dimension = dimensions[j];
            int *arr = (int *)malloc(dimension * sizeof(int));

            if (arr == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }

            // Initialize the array with data (e.g., in reverse order)
            for (int k = 0; k < dimension; k++)
            {
                arr[k] = dimension - k;
            }

            double execution_time = sorting_function(arr, dimension);
            matrix[i][j] = execution_time;

            free(arr); // Free the dynamically allocated array
        }
    }

    FILE *dataFile = fopen("data.txt", "w");
    if (dataFile == NULL)
    {
        printf("Failed to open data file for writing\n");
        return 1;
    }

    // Write the data to the file with separate columns for each sorting method
    fprintf(dataFile, "Dimension ShellSort Selection BubbleSort Insertion CocktailSort CombSort OddEvenSort\n");

    for (int j = 0; j < max_dimensions; j++)
    {
        fprintf(dataFile, "%d ", dimensions[j]);
        for (int i = 0; i < MAX_METHODS; i++)
        {
            fprintf(dataFile, "%f ", matrix[i][j]);
        }
        fprintf(dataFile, "\n");
    }

    fclose(dataFile);

    return 0;
}
