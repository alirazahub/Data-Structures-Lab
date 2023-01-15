#include <iostream>
using namespace std;

void linearSearch(int array[],int size,int key){
    int i;
    for(i=0;i<size;i++){
        if(array[i]==key){
            cout<<"Found at "<<i+1<<endl;
            return;
        }
    }
    cout<<"Not Found"<<endl;
}

void binarySearch(int array[],int size,int key){
    int l=0,r=size-1,m;
    while(l<=r){
        m = (l+r)/2;
        if(array[m]==key){
            cout<<"Found at "<<m+1<<endl;
            return;
        }
        else if(array[m]<key){
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    cout<<"Not Found"<<endl;
}

void printArray(int array[],int size){
    int i;
    for(i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main (){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array)/sizeof(array[0]);
    int key = 1;

    linearSearch(array,size,key);
    binarySearch(array,size,key);

    return 0;
}