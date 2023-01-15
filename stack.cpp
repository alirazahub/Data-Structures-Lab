#include <iostream>

using namespace std;
const int MAX = 100;
int stack[MAX];
int top = -1;

bool isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
bool isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}
void push(int num)
{
    if(isFull())
    {
        cout<<endl<<"Error! ***OverFlow***"<<endl;
    }
    else
    {
        top++;
        stack[top] = num;
        cout<<endl<<"Value Pushed Successfully!"<<endl;
    }
}

void pop()
{
    if(isEmpty())
    {
        cout<<endl<<"Error! ***--UnderFlow--***"<<endl;
    }
    else
    {
        cout<<endl<<"Value "<<stack[top]<< " Poped Successfully!"<<endl;
        top--;
    }
}

void display()
{
    if(isEmpty())
    {
        cout<<endl<<"Error! ***--UnderFlow--***"<<endl;
    }
    else
    {
        cout<<endl<<"Stack Elements are: ";
        for(int i=0; i<=top; i++)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    push(10);
    push(20);
    display();
    pop();
    pop();
    push(30);
    display();
    return 0;
}
