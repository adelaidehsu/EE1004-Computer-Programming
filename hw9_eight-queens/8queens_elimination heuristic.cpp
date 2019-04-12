//
//  main.cpp
//  Homework_9
//  8queens by elimination heuristic.
//  Created by B04705036 on 11/20/2016.
//
//

#include <iostream>
#include <iomanip>
using namespace std;

int lowestMax(int e[8][8], int &r, int &c, int lowest); //determines the best square to choose
int max(int e[8][8], int r, int c); //determines the highest elimination square affected by a certain square on the board
void place8Queens(int e[8][8], int b[8][8], int r, int c, int &queen);
void reduceE(int e[8][8], int r, int c); //updates the elimination array based on the chosen square
void updateE(int e[8][8], int b[8][8], int r, int c); //updates the elimination array based on the chosen square
void placeQueen(int e[8][8], int b[8][8], int r, int c, int &queen);
void nextLocation(int e[8][8], int b[8][8], int &r, int &c); //determine the next location to put a queen
void printArray(int a[8][8]);

int used = 5000;

int main()
{
    
    int e[8][8] = {{22,22,22,22,22,22,22,22},
        {22,24,24,24,24,24,24,22},
        {22,24,26,26,26,26,24,22},
        {22,24,26,28,28,26,24,22},
        {22,24,26,28,28,26,24,22},
        {22,24,26,26,26,26,24,22},
        {22,24,24,24,24,24,24,22},
        {22,22,22,22,22,22,22,22}};
    
    int b[8][8] = {0};
    
    int r;
    int c;
    int queen = 1;
    
    place8Queens(e,b,r,c,queen);
    system("pause");
    
    return 0;
}

void place8Queens(int e[8][8], int b[8][8], int r, int c, int &queen)
{
    bool firstrun = false;
    
    for(int i = 0; i < 8; ++i)
    {
        if(firstrun == true)
        {
            r = 0;
            c = 0;
            firstrun = false;
        }
        else
        {
            nextLocation(e, b, r, c);
        }
        
        placeQueen(e, b, r, c, queen);
    }
    
    
}

void reduceE(int e[8][8], int r, int c)
{
    for(int i = 0; i < 8; ++i)
    {
        
        --e[r][i];
    }
    
    for(int i = 0; i < 8; ++i)
    {
        --e[i][c];
    }
    
    //down-right
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c + i > 7)
            i = 8;
        else
            --e[r + i][c + i];
    }
    
    //up-right
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c + i > 7)
            i = 8;
        else
            --e[r - i][c + i];
    }
    
    //up-left
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c - i < 0)
            i = 8;
        else
            --e[r - i][c - i];
    }
    
    //down-left
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c - i < 0)
            i = 8;
        else
            --e[r + i][c - i];
    }
    
}

void placeQueen(int e[8][8], int b[8][8], int r, int c, int &queen)
{
    b[r][c] = queen++;
    
    updateE(e, b, r, c);
    
    printArray(b);
    //printArray(e);
}

void updateE(int e[8][8], int b[8][8], int r, int c)
{
    for(int i = 0; i < 8; ++i)
    {
        if(e[r][i] < 1000)
        {
            e[r][i] = used;
            reduceE(e, r, i);
        }
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(e[i][c] < 1000)
        {
            e[i][c] = used;
            reduceE(e, i, c);
        }
    }
    
    //down-right
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c + i > 7)
            i = 8;
        else
        {
            if(e[r + i][c + i] < 1000)
            {
                e[r + i][c + i] = used;
                reduceE(e, r+i, c+i);
            }
        }
    }
    
    //up-right
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c + i > 7)
            i = 8;
        else
        {
            if(e[r - i][c + i] < 1000)
            {
                e[r - i][c + i] = used;
                reduceE(e, r-i, c+i);
            }
        }
    }
    
    //up-left
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c - i < 0)
            i = 8;
        else
        {
            if(e[r - i][c - i] < 1000)
            {
                e[r - i][c - i] = used;
                reduceE(e, r-i, c-i);
            }
        }
    }
    
    //down-left
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c - i < 0)
            i = 8;
        else
        {
            if(e[r + i][c - i] < 1000)
            {
                e[r + i][c - i] = used;
                reduceE(e, r+i, c-i);
            }
        }
    }
    
    
    
}

void nextLocation(int e[8][8], int b[8][8], int &r, int &c)
{
    
    
    int lowest = 500;
    
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(e[i][j] < lowest)
            {
                lowest = e[i][j];
            }
        }
    }
    
    
    
    lowestMax(e, r, c, lowest);
    
}

int lowestMax(int e[8][8], int &r, int &c, int lowest)
{
    int min = 300;
    int r2, c2;
    
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(e[i][j] == lowest)
            {
                if(max(e, i, j) < min)
                {
                    min = max(e, i, j);
                    r2 = i;
                    c2 = j;
                }
            }
        }
    }
    
    cout << "Proposed target - r: " << r2+1 << " c: " << c2+1 << endl;
    
    
    r = r2;
    c = c2;
    
    return min;
}

int max(int e[8][8], int r, int c)
{
    int max = 0;
    
    for(int i = 0; i < 8; ++i)
    {
        if(e[r][i] < 1000)
        {
            if(e[r][i] > max)
                max = e[r][i];
        }
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(e[i][c] < 1000)
        {
            if(e[i][c] > max)
                max = e[i][c];
        }
    }
    
    //down-right
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c + i > 7)
            i = 8;
        else
        {
            if(e[r + i][c + i] < 1000)
            {
                if(e[r + i][c + i] > max)
                    max = e[r + i][c + i];
            }
        }
    }
    
    //up-right
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c + i > 7)
            i = 8;
        else
        {
            if(e[r - i][c + i] < 1000)
            {
                if(e[r - i][c + i] > max)
                    max = e[r - i][c + i];
            }
        }
    }
    
    //up-left
    for(int i = 0; i < 8; ++i)
    {
        if(r - i < 0 || c - i < 0)
            i = 8;
        else
        {
            if(e[r - i][c - i] < 1000)
            {
                if(e[r - i][c - i] > max)
                    max = e[r - i][c - i];
            }
        }
    }
    
    //down-left
    for(int i = 0; i < 8; ++i)
    {
        if(r + i > 7 || c - i < 0)
            i = 8;
        else
        {
            if(e[r + i][c - i] < 1000)
            {
                if(e[r + i][c - i] > max)
                    max = e[r + i][c - i];
            }
        }
    }
    
    return max;
    
}

void printArray(int a[8][8])
{
    
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(a[i][j] == 0)
                cout << setw(1) << "." << " ";
            else
                cout << setw(1) << a[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
}


