//
//  HW12.cpp
//  HW12
//
//  Created by Aliyah on 12/8/16.
//  Copyright © 2016 Aliyah. All rights reserved.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


struct node
{
    int data;
    node *next;
};

void swap(node *, node *);
void selectionsort(node *);
void display(node *, int);

int main()
{
    srand(time(0));
    int term;
    
    cout<<"how many integers:"<<endl;
    cin>>term;
    
   /** node *b[]= {0};
    for(int i=0; i<term; i++)
    {
        b[i] = new node;
    }
    **/
    vector <node*> b;
    for(int i=0; i<term; i++)
    {node* ptr=new node;b.push_back(ptr);}
    b[term-1] -> next =0;
    
    for(int i=0; i<term; i++)
    {
        b[i] -> data = rand()%101;
    }
    
    for(int i=0; i<term-1; i++)
    {
        b[i] -> next = b[i+1];
    }
    
    selectionsort(b[0]);
    display(b[0], term);
    
    system("pause");
    return 0;
    
}

void swap(node *ptr1, node *ptr2)
{
    int hold = ptr1 -> data;
    ptr1 -> data = ptr2 -> data;
    ptr2 -> data = hold;
}

void selectionsort(node *first)
{
    int size =1;
    node *p = first;
    node *curr = first -> next;
    while(p -> next != 0)//size==term
    {
        size++;
        p =p -> next;
    }
    p=first;
    
    for(int i=0; i<size; i++)
    {
        for(int j=i; j<size; j++)
        {
            if(p -> data > curr -> data)
                swap(p, curr);
            if(curr -> next!=0)curr = curr -> next;
        }
        if(p->next!=0)p= p -> next;
        curr=p;
    }
}


void display(node *list, int size)
{
    
    if(list==NULL)
    {
        cout<<"empty."<<endl;
    }
    for(int i=0;i<size;i++)
    {
        cout<<list->data<<" "<<endl;
        list=list->next;
    }
}



