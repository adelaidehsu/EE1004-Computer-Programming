//
//  main.cpp
//  HW11_selection sort
//
//  Created by Aliyah on 12/1/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionsort(int [], int, int);
void swap(int *, int *);

int main ()
{
    srand(time(0));
    int arraysize;
    
    cout<<"please enter how many numbers to be sorted:"<<endl;
    cin>> arraysize;
    
    int a[arraysize];
    
    for (int i=0; i<arraysize; i++)
        a[i] = rand()%50+1;
    
    cout<<"unsorted array:"<<endl;
    for (int i=0; i<arraysize; i++)
    {
        cout << a[i]<< " ";
    }
    cout<<endl;
    
    
    selectionsort(a, arraysize, arraysize);
    
    cout<<"sorted array using selection sort algorithm:"<<endl;
    
    for(int i=0; i<arraysize; i++)
    {
        cout<< a[i]<<" ";
    }
    cout<<endl;
    
    system("pause");
    return 0;
    
}


void selectionsort(int data[], int arraysize, int arraysizefixed)
{
    int index = arraysizefixed-arraysize;
    int smallest = index;
    
    if (arraysize>0)
    {
        for(int j=index+1; j<arraysizefixed; j++)
        {
            if(data[j]<data[smallest])
            {
                smallest = j;
            }
        }
        
        swap(&data[smallest], &data[index]);
        selectionsort(data, arraysize-1, arraysizefixed);
    }
}

void swap(int *ptr1, int *ptr2)
{
    int hold = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = hold;
}

