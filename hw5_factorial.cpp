//Homework_5: the execution of factorial.
//2016.10.18_by B04705036

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	int number;
	int factorial;
	int choice;

	
	cout<< "choose which program you want to execute. 1: factorial  2: seires of the reciprocal of factorials  3: e^x of n series."<<endl;
	cin>> choice;
	
	if (choice== 1)
	{
	   cout<<"Please enter a nonnegative integer you'd like to perform factorial."<<endl;
	   cin>>number;
	
	   if (number>0)
	   {
	     	factorial = 1;
	        for(int i=1; i<=number; i++)
	        	factorial= factorial*i;
				cout<<number<<"!="<<factorial<<endl;	
	   }  
	   
	   else if (number ==0)
	   	{
	   		cout<<"0!=1"<<endl;
		}
		    
	   else
	   {
	   		cout<<"wrong inputs. please try again."<<endl;
	   }
    
	}
	   
	   
	if (choice == 2)   
	{
		int denominator=1;
		double series_n = 1.0;
		int desired_accu;
		
		cout<< "Please enter a nonnegative integer n that you'd like to perform  1 + 1/1! + 1/2! + .... + 1/(n-1)! + 1/n! ." << endl;
		cin>> number;
		
		for (int j=1; j<= number; j++)
		{
			denominator *=j;
			series_n += 1.0/denominator;
		}
		
		cout<<"What's your desired accuracy for the seires? (_____ degits to the right of the decimal point.)"<<endl;
		cin>> desired_accu;
		cout<< setprecision (desired_accu)<< fixed << "the n series equals to =" << series_n<<endl;
		
	}
	   
	
	   
	
	if (choice == 3)
	{
		int x;
		int denominator=1;
		int numerator;
		double result = 1.0;
		int desired_accu_1;
		
		cout<<"Please enter a nonnegative integers x. " << endl;
		cin>> x;
		cout<<"Please enter a nonnegative integer n." << endl;
		cin>> number;
		
		for (int k=1; k<= number; k++)
		{
			denominator*=k;
			numerator = pow (x,k);
			result += static_cast <double> (numerator)/denominator ;
		}
	
		cout<<"What's your desired precision for e^x? (____ digits to the right of the decimal point.)"<<endl;
		cin>> desired_accu_1;
		cout<<setprecision (desired_accu_1)<<fixed<<"e^"<<x<<"="<< result <<endl;
	}
    
    
    
	system ("pause");
	return 0;
}
