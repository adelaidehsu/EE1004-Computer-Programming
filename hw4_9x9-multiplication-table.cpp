//2016.10.13_Homework3_by_B04705036
//create a multiplication table from 1x1 to 9x9 using while, for and do.....while syntaxes.

#include<iostream>
using namespace std;

int main()
{
	int mode;

	cout << "Choose one technique to produce the multiplication table. (1:for 2:while 3:do...while)";
	cin >> mode;

	if (mode == 1)
	{
		for (int i = 1; i<=9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				cout << i << "*" << j << "=" << i*j << endl;
			}
			
			cout << endl;

		}
	}


	if (mode == 2)
	{
		int i = 1;

		while (i <= 9)
		{
			int j = 1;
			while (j <= 9)
			{
				cout << i << "*" << j << "=" << i*j << endl;
				j++;
			}
			i++;
		}
	}

		if (mode == 3)
		{
			int i, j;
			i = 1;

			do
			{
				j = 1;
				do
				{
					cout << i << "*" << j << "=" << i*j << endl;
					j++;
				} while (j <= 9);
				i++;
			} while (i <= 9);
		}
	
	system("pause");
	return 0;
}