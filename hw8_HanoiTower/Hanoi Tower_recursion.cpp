//
//  main.cpp
//  homework 8_Hanoi Tower_recursion.
//
//  Created by B04705036 on 11/13/16.
//
//

#include <iostream>
using namespace std;

void hanoi (int n, int a, int b, int c);

int main ()
{
    int number;
    int A=1;
    int B=2;
    int C=3;
    
    cout<< "enter the number of disks."<<endl;
    cin>> number;
    
    hanoi (number, A, B, C );
    
    system ("pause");
    return 0;
    
}

void hanoi(int n, int a, int b, int c)
{
    if (n == 1)
    {
        cout << a << "->" << c <<endl;
    }
    else
    {
        hanoi (n-1, a, c, b);
        cout << a << "->" << c <<endl;
        hanoi (n-1, b, a, c);
    }
}



