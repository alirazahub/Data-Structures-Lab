#include<iostream>
using namespace std;

void swapp(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}
void quickSort(int array[], int low, int high)
{
    if(low<=high){
        int pivot = array[low];
        int i = low +1;
        int j = high;
        while(i<=j){
            while(array[i]<=pivot)
                i++;
            while(array[j]>pivot){
                j--;
            }
            if(i<j){
                swapp(array[i],array[j]);
            }
        }
        swapp(array[low],array[j]);
        quickSort(array,low,j-1);
        quickSort(array,j+1,high);
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
int main(){

    int n = 10;
    int array[n] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
    printArray(array, n);
    quickSort(array, 0, n - 1);
    printArray(array, n);

    return 0;
}