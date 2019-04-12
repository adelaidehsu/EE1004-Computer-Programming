//
//  Rational.h
//  HW13
//
//  Created by Aliyah on 12/17/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#ifndef Rational_h
#define Rational_h

class Rational
{
public:
    Rational(int =1, int =2);
    void add(Rational, Rational);
    void subtract(Rational, Rational);
    void multiply(Rational, Rational);
    void divide(Rational, Rational);
    void printfraction();
    void printfloat();
    int getnum();
    int getdeno();
    void setnum(int);
    void setdeno(int);
    void check(int, int);
    
private:
    int numerator;
    int denominator;
   
};

#endif /* Rational_h */
