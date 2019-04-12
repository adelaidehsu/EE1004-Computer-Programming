//
//  Rational.cpp
//  HW13
//
//  Created by Aliyah on 12/17/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#include "Rational.h"
#include <iostream>
#include<iomanip>
using namespace std;

void Rational::check(int num, int deno)
{
    if(num>=deno)
    {
        for(int i=1; i<=deno; i++)
        {
            if(num%i==0 && deno%i==0)
            {
                numerator = num/i;
                denominator = deno/i;
            }
        }
    }
    
    if(deno>num)
    {
        for(int i=1; i<=num; i++)
        {
            if(num%i==0 && deno%i==0)
            {
                numerator = num/i;
                denominator = deno/i;
            }
        }
    }
}

Rational::Rational(int num, int deno)
{
    check(num, deno);
}

int Rational::getnum()
{
    return numerator;
}

int Rational::getdeno()
{
    return denominator;
}

void Rational::setnum(int num)
{
    numerator = num;
}

void Rational::setdeno(int deno)
{
    denominator = deno;
}

void Rational::add(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t2.getdeno() * t1.getdeno());
    t3.setnum(t2.getnum()*t1.getdeno()+t1.getnum()*t2.getdeno());
    check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}

void Rational::subtract(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t2.getdeno() * t1.getdeno());
    t3.setnum(t1.getnum()*t2.getdeno()-t2.getnum()*t1.getdeno());
    check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}

void Rational::multiply(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t2.getdeno() * t1.getdeno());
    t3.setnum(t1.getnum()*t2.getnum());
    check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}

void Rational::divide(Rational t1, Rational t2)
{
    Rational t3;
    t3.setdeno(t1.getdeno() * t2.getnum());
    t3.setnum(t1.getnum()*t2.getdeno());
    check(t3.getnum(), t3.getdeno());
    cout<<t3.getnum()<<"/"<<t3.getdeno()<<endl;
}

void Rational::printfraction()
{
    cout<<numerator<<"/"<<denominator<<endl;
}

void Rational::printfloat()
{
    cout<<static_cast<float>(numerator)/denominator<<endl;
}
