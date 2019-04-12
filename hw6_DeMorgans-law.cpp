//2016.08.25due
//homework6: De Morgan's Laws_ by B04705036

#include<iostream>
using namespace std;
using std::boolalpha;
using std::cout;

int main()
{
	bool comparison1, comparison2, comparison3, comparison4, comparison5, comparison6, comparison7, comparison8;
	int x=3;
	int y=9;
	int a=5;
	int b=6;
	int g=2;
	int i=8;
	int j=4;

	
	{
		bool comparison1 = (x >= 5) && ( y < 7);
		bool comparison2 = !(( x < 5) || ( y >= 7));
		
		if (comparison1 == comparison2)
			cout<<" !(x < 5) && !( y >= 7) is equivalent to  !(( x < 5) || ( y >= 7))" <<endl;
		else
			cout<<"  !(x < 5) && !( y >= 7) is not equivalent to  !(( x < 5) || ( y >= 7))" << endl;
	}
	
	{
		bool comparison3 = ( a != b) || ( g ==5);
		bool comparison4 = !(( a == b) && ( g != 5));
		
		if (comparison3 == comparison4)
			cout<<" !( a == b) || !( g != 5) is equivalent to !(( a == b) && ( g != 5))" <<endl;
		else
			cout<<" !( a == b) || !( g != 5) is not equivalent to !(( a == b) && ( g != 5))" <<endl;
	}
	
	{
		bool comparison5 = !(( x <= 8) && (y >4));
		bool comparison6 = ( x > 8) || ( y <= 4);
		
		if (comparison5 == comparison6)
			cout<<" !(( x <= 8) && (y >4)) is equivalent to ( x > 8) || ( y <= 4)" <<endl;
		else
			cout<<" !(( x <= 8) && (y >4)) is not equivalent to ( x > 8) || ( y <= 4)"<<endl;
	}
	
	{
		bool comparison7 = !(( i > 4) || ( j <= 6));
		bool comparison8 = ( i <=4) && ( j > 6);
		
		if (comparison7 == comparison8)
			cout<<" !(( i > 4) || ( j <= 6)) is equivalent to (i <= 4) && ( J > 6)"<<endl;
		else
			cout<<" !(( i > 4) || ( j <= 6)) is not equivalent to (i <= 4) && ( J > 6)"<<endl;
	}
	
	system("pause");
	return 0;
}
