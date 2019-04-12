//homework7_by B04705036

#include <iostream>
using namespace std;

int main ()
{

	for (int n=0; n<5; n++)
	{
		for (int k=5; k>n; k--)
			cout << " ";
		for (int j=0; j<n; j++)
			cout << "*";
		
		for (int j=1; j<n; j++)
			cout << "*";
			
		for (int k=5; k>n; k--)
				cout << " ";
		cout<<endl;
	
	}
	
		for (int n=5; n>0; n--)
	{
		for (int k=5; k>n; k--)
			cout << " ";
		for (int j=0; j<n; j++)
			cout << "*";
			
		for (int j=1; j<n; j++)
			cout << "*";
			
		for (int k=5; k>n; k--)
			cout << " ";

		cout<<endl;
	}
	
	system ("pause");
	return 0;
}
