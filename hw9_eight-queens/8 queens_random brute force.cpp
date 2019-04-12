//
//  main.cpp
//  Homework_9
//  8 queens by random brute force.
//  Created by Aliyah on 11/20/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void resetB(int b[8][8]);
bool full(int b[8][8]);
void updateB(int b[8][8], int r, int c);
void printArray(int a[8][8]);

int main()
{
    srand(time(0));
    
    int b[8][8] = {0};
    
    int r;
    int c;
    int queens = 0;
    int failures = 0;
    
    while(queens != 8)
    {
        if(full(b))
        {
            failures++;
            printArray(b);
            queens = 0;
            resetB(b);
        }
        
        r = rand() % 8;
        c = rand() % 8;
        
        if(b[r][c] == 0)
        {
            b[r][c] = 1;
            queens++;
        }
    }
    
    printArray(b);
    cout << "Failures: " << failures << endl;
    
    system("pause");
    
    return 0;
}

void resetB(int b[8][8])
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            b[i][j] = 0;
        }
    }
}

bool full(int b[8][8])
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(b[i][j] == 1)
            {
                updateB(b,i,j);
            }
        }
    }
    
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(b[i][j] == 0)
                return false;
        }
    }
    
    return true;
}

void updateB(int b[8][8], int r, int c)
{
    for(int i = 0; i < 8; ++i)
        if(b[r][i] == 0)
            b[r][i] = 2;
    
    for(int i = 0; i < 8; ++i)
        if(b[i][c] == 0)
            b[i][c] = 2;
    
    //down-right
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c + i > 7)
            i = 8;
        else if(b[r+i][c+i] == 0)
            b[r + i][c + i] = 2;
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c - i < 0)
            i = 8;
        else if(b[r+i][c-i] == 0)
            b[r + i][c - i] = 2;
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c + i > 7)
            i = 8;
        else if(b[r-i][c+i] == 0)
            b[r - i][c + i] = 2;
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c - i < 0)
            i = 8;
        else if(b[r-i][c-i] == 0)
            b[r - i][c - i] = 2;
    }
    
}

void printArray(int a[8][8])
{
    
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(a[i][j] == 0)
                cout << setw(1) << "." << " ";
            else if(a[i][j] == 1)
                cout << setw(1) << "Q" << " ";
            else if(a[i][j] == 2)
                cout << setw(1) << "." << " ";
        }
        cout << endl;
    }
    
    cout << endl;
}
