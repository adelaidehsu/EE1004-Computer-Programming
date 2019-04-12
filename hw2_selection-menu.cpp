//
//  main.cpp
//  C++ Homework_2
//
//  Created by Aliyah on 10/3/16.
//  Menu for selection: multiplication or addition.
//

#include <iostream>

int main()

{
    int number1;
    int number2;
    int number3;
    int choice;
    int product;
    int sum;
    
    
    std::cout<< "please enter 1 or 2";
    std::cin>> choice;
    
    std::cout<< "please enter three integers.";
    std::cin>> number1 >> number2 >> number3;
    
    product = number1*number2*number3;
    sum = number1+ number2+number3;
    
    if (choice==1)
        std::cout<< product << std::endl;
    
    if (choice==2)
        std::cout<< sum << std::endl;
    
    system ("pause");
    
    return 0;
}
