#include <time.h>
#include <stdio.h>

double CocktailSort(int arr[], int n)
{
    float start_time, end_time;
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
