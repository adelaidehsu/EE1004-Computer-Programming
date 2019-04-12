//
//  main.cpp
//  HW13
//
//  Created by Aliyah on 12/17/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#include <iostream>
#include"Rational.h"
using namespace std;
#include<iomanip>

void add(Rational, Rational);
void subtract(Rational, Rational);
void multiply(Rational, Rational);
void divide(Rational, Rational);

int main()
{
    Rational first(5,6);
    Rational second(3,7);
    
    cout<<"print the first fraction:";
    first.printfraction();
    cout<<"first fraction in floating-point format:";
    first.printfloat();
    
    cout<<"print the second fraction:";
    second.printfraction();
    cout<<"second fraction in floating-point format:";
    second.printfloat();
    
    cout<<"the addition of two Rational numbers:";
    add(first, second);
    
    cout<<"the subtraction of two Rational numbers:";
    subtract(first,second);
    
    cout<<"the product of two Rational numbers:";
    multiply(first, second);
    
    cout<<"the quotient of two Rational numbers:";
    divide(first, second);
    
    system("pause");
    return 0;
    
}

void add(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t2.getdeno() * t1.getdeno());
    t3.setnum(t2.getnum()*t1.getdeno()+t1.getnum()*t2.getdeno());
    t3.check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}

void subtract(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t2.getdeno() * t1.getdeno());
    t3.setnum(t1.getnum()*t2.getdeno()-t2.getnum()*t1.getdeno());
    t3.check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}

void multiply(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t2.getdeno() * t1.getdeno());
    t3.setnum(t1.getnum()*t2.getnum());
    t3.check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}

void divide(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t1.getdeno() * t2.getnum());
    t3.setnum(t1.getnum()*t2.getdeno());
    t3.check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}
