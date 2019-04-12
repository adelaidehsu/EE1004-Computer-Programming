//
//  main.cpp
//  HW11
//
//  Created by Aliyah on 11/29/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    
    int a[3][3];
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            a[i][j] = rand()%50 +1;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int sum1=0;
    int avg1=0;
    for(int j=0; j<3; j++)
        sum1 += a[0][j];
    avg1 = sum1/3;
    
    int sum2=0;
    int avg2=0;
    for(int j=0; j<3; j++)
        sum2 += a[1][j];
    avg2 = sum2/3;
    
    int sum3=0;
    int avg3=0;
    for(int j=0; j<3; j++)
        sum3 += a[2][j];
    avg3 = sum3/3;
    
    int sumofdie1 = 0;
    for(int i=0; i<3; i++)
        sumofdie1 += a[i][i];
    
    int sumofdie2 =0;
    for(int i=0; i<3; i++)
        sumofdie2 += a[i][2-i];
    
    cout<< "1st row sum:" << sum1<<" , avg:" <<avg1<<endl;
    cout<<"2nd row sum:" <<sum2<<" , avg:"<<avg2<<endl;
    cout<<"3rd row sum:"<<sum3<<" ,avg:"<<avg3<<endl;
    cout<<"2 diagonals:"<<sumofdie1<<" , "<<sumofdie2<<endl;
    
    system ("pause");
    return 0;
    
}
