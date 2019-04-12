//
//  main.cpp
//  8 queens by exhaustive brute force.
//
//  Created by Aliyah on 11/21/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

void resetB(int b[8][8]);
bool solved(int b[8][8]);
bool queen(int b[8][8], int r, int c);
void printArray(int b[8][8]);

int main()
{
    int board[8][8] = {0};
    int solutions = 0;
    
    for(int a = 0; a < 8; ++a) {
        for(int b = 0; b < 8; ++b) {
            for(int c = 0; c < 8; ++c) {
                for(int d = 0; d < 8; ++d) {
                    for(int e = 0; e < 8; ++e) {
                        for(int f = 0; f < 8; ++f) {
                            for(int g = 0; g < 8; ++g) {
                                for(int h = 0; h < 8; ++h) {
                                    resetB(board);
                                    
                                    board[a][0] = 1;
                                    board[b][1] = 1;
                                    board[c][2] = 1;
                                    board[d][3] = 1;
                                    board[e][4] = 1;
                                    board[f][5] = 1;
                                    board[g][6] = 1;
                                    board[h][7] = 1;
                                    
                                    if(solved(board))
                                    {
                                        solutions++;
                                        printArray(board);
                                    }
                                    
                                    
                                }}}}}}}}
    
    cout << "Solutions: " << solutions << endl;
    cout << solutions / 4 << endl;
    
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

bool solved(int b[8][8])
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(b[i][j] == 1)
            {
                if(queen(b,i,j))
                    return false;
            }
        }
    }
    
    return true;
}

bool queen(int b[8][8], int r, int c)
{
    //right
    for(int i = 1; i < 8; ++i)
        if(c + i > 7)
            i = 8;
        else if(b[r][c + i] == 1)
            return true;
    //left
    for(int i = 1; i < 8; ++i)
        if(c - i < 0)
            i = 8;
        else if(b[r][c - i] == 1)
            return true;
    //down
    for(int i = 1; i < 8; ++i)
        if(r + i > 7)
            i = 8;
        else if(b[r+i][c] == 1)
            return true;
    
    //up
    for(int i = 1; i < 8; ++i)
        if(r - i < 0)
            i = 8;
        else if(b[r-i][c] == 1)
            return true;
    
    //down-right
    for(int i = 1; i < 8; ++i)
    {
        if(r + i > 7 || c + i > 7)
            i = 8;
        else if(b[r+i][c+i] == 1)
            return true;
    }
    
    for(int i = 1; i < 8; ++i)
    {
        if(r + i > 7 || c - i < 0)
            i = 8;
        else if(b[r+i][c-i] == 1)
            return true;
    }
    
    for(int i = 1; i < 8; ++i)
    {
        if(r - i < 0 || c + i > 7)
            i = 8;
        else if(b[r-i][c+i] == 1)
            return true;
    }
    
    for(int i = 1; i < 8; ++i)
    {
        if(r - i < 0 || c - i < 0)
            i = 8;
        else if(b[r-i][c-i] == 1)
            return true;
    }
    
    return false;
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

