//
//  HW11_quicksort.cpp
//  
//
//  Created by B04705036 on 12/1/16.
//
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quicksort(int [], int, int);
int partition(int, int, int []);

int main ()
{
    srand(time(0));
    int arraysize;
    cout<<"please enter how many numbers to be sorted:"<<endl;
    cin>>arraysize;
    
    int a[arraysize];
    
    for(int i=0; i<arraysize; i++)
        a[i] = rand()%50+1;
    
    cout<<"unsorted array:"<<endl;
    for(int i=0; i<arraysize; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    quicksort(a, 0, arraysize-1);
    cout<<"array sorted using quicksort:"<<endl;
    for(int i=0; i<arraysize; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    system("pause");
    return 0;
    
}

void quicksort(int data[], int bottom, int top)
{
    int middle;
    if (top > bottom)
    {
        middle = partition(bottom, top, data);
        quicksort(data, bottom, middle);
        quicksort(data, middle+1, top);
    }
    
    return;
    
}

int partition(int bottom, int top, int data[])
{
    int x = data[bottom];
    int i = bottom-1;
    int j = top+1;
    
    do
    {
        do
        {
            i++;
        }while(data[i]<x);
        
        do
        {
            j--;
        }while(data[j]>x);
        
        if(i<j)
        {
            int hold = data[i];
            data[i]=data[j];
            data[j]=hold;
        }
    }while(i<j);
    
    return j;
    
}
