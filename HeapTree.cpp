#include <iostream>
using namespace std;

const int MAX = 100;
int stack[MAX];
int top = -1;

bool isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
bool isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
void push(int num)
{
    if (isFull())
    {
        cout << endl
             << "Error! ***OverFlow***" << endl;
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << endl
             << "Error! ***--UnderFlow--***" << endl;
    }
    else
    {
        top--;
    }
}

void printStack()
{
    if (isEmpty())
    {
        cout << endl
             << "Error! ***--UnderFlow--***" << endl;
    }
    else
    {
        cout << endl
             << "Stack Elements are: ";
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
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

void SortMaxHeapUsingStack()
{
    while (heapSize != 0)
    {
        push(heap[0]);
        swapp(heap[0], heap[heapSize - 1]);
        heapSize--;
        shiftDown(0);
    }
    while (!isEmpty())
    {
        cout << stack[top] << " ";
        pop();
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

    // SortMaxHeapUsingStack();
    // printHeap();
    return 0;
}
