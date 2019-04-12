//Sep.21.2016 C++ homework
//the multiplication of three numbers

#include <iostream>

int main()
{
	int x1;
	int x2;
	int x3;
	int multiplication;

	std::cout << "please enter three integers.";
	std::cin >> x1 >> x2 >> x3;

	multiplication = x1*x2*x3;

		std::cout << "the multiplication is:" << multiplication << std::endl;

		system("pause");
	return 0;

}