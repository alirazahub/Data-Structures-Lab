#include <iostream>
using namespace std;

void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void insertionSort(int array[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            swapp(array[j], array[j - 1]);
            j--;
        }
    }
}
void selectionSort(int array[], int size)
{
    int i, j, min;
    for (i = 0; i < size; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swapp(array[i], array[min]);
    }
}

void bubbleSort(int array[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swapp(array[j], array[j + 1]);
            }
        }
    }
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = array[low];
        int i = low + 1;
        int j = high;
        while (i <= j)
        {
            while (array[i] <= pivot)
            {
                i++;
            }
            while (array[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                swapp(array[i], array[j]);
            }
        }
        swapp(array[low], array[j]);
        quickSort(array, low, j - 1);
        quickSort(array, j + 1, high);
    }
}

void merg(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merg(array, l, m, r);
    }
}

void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 10;
    int array[n] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
    printArray(array, n);
    quickSort(array, 0, n - 1);
    printArray(array, n);
    return 0;
}
