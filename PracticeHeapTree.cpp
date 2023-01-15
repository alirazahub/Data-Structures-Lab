#include <iostream>
using namespace std;

#define MAX 100
int Queue[MAX];
int F = -1;
int R = -1;

void insertAtEnd(int value)
{
    if (((F == 0) && (R == MAX - 1)) || (F == R + 1))
    {
        cout << endl
             << "***--OverFlow--***" << endl;
    }
    else if (F == -1 && R == -1)
    {
        F = 0;
        R = 0;
        Queue[R] = value;
    }
    else if (F != 0 && R == MAX - 1)
    {
        R = 0;
        Queue[R] = value;
    }
    else
    {
        R++;
        Queue[R] = value;
    }
}

void deleteFromFront()
{
    if ((F == -1) && (R == -1))
    {
        cout << "**--Underflow--**" << endl;
    }
    else if (F == R)
    {
        cout << " " << Queue[F] << " ";
        F = -1;
        R = -1;
    }
    else if (F == MAX - 1)
    {
        cout << " " << Queue[F] << " ";
        F = 0;
    }
    else
    {
        cout << " " << Queue[F] << " ";
        F++;
    }
}

#define SIZE 100
int heap[SIZE];
int heapSize = 0;
int parent(int i)
{
    return (i - 1) / 2;
}
int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * i + 2;
}

void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void shiftUp(int i)
{
    while (i > 0 && heap[parent(i)] < heap[i])
    {
        swapp(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void shiftDown(int i)
{
    int maxIndex = i;
    int l = left(i);
    if (l < heapSize && heap[l] > heap[maxIndex])
        maxIndex = l;
    int r = right(i);
    if (r < heapSize && heap[r] > heap[maxIndex])
        maxIndex = r;
    if (i != maxIndex)
    {
        swapp(heap[i], heap[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insertion(int value)
{
    if (heapSize == SIZE)
    {
        cout << "Heap is full" << endl;
        return;
    }
    heapSize++;
    heap[heapSize - 1] = value;
    shiftUp(heapSize - 1);
}

void printHeap()
{
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

void SortMaxHeapUsingQueue()
{
    while (heapSize != 0)
    {
        insertAtEnd(heap[0]);
        swapp(heap[0], heap[heapSize - 1]);
        heapSize--;
        shiftDown(0);
    }
    while (true)
    {
        if (R == -1)
        {
            return;
        }
        else
        {
            deleteFromFront();
        }
    }
}

int main()
{
    insertion(50);
    insertion(20);
    insertion(40);
    insertion(30);
    insertion(10);
    insertion(60);
    printHeap();

    SortMaxHeapUsingQueue();
    printHeap();
    return 0;
}
