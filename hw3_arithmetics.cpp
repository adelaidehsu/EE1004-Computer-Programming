//
//  homework_3
//
//  Created by B04705036 on 10/17/16.
//  加減乘除運算器 
//

#include<iostream>
using namespace std;

int main()
{
  int a,b;
  char letter;
  while(true)
  {
  	cout<<"please enter two integers:"<<endl;
  	cin>>a>>b;
  	cout<<"a=" <<a<<";b="<<b<<endl;
  	cout<<"what arithmetics do you want to do with a and b? (+,-,*,/)\nEnter ';' to restart. Please enter:"<<endl;
  	
  	while(cin>>letter&&letter!=';')
  	{
	  switch (letter)
	  {
	  	case '+':
	  		cout<< a<<letter<<b<<"="<<a+b<<endl;
	  		cout<<"what arithmetics do you want to do with a and b? (+,-,*,/)\nenter ; to restart. please enter:";
	  		break;
	  	case '-':
	  		cout<<a<<letter<<b<<"="<<a-b<<endl;
	  		cout<<"what arithmetics do you want to do with a and b? (+,-,*,/)\nenter ; to restart. please enter:";
	  		break;
	  	case '*':
	  		cout<<a<<letter<<b<<"="<<a*b<<endl;
	  		cout<<"what arithmetics do you want to do with a and b? (+,-,*,/)\nenter ; to restart. please enter:";
	  		break;
	  	case '/':
	  		cout<<a<<letter<<b<<"="<<a/b<<endl;
	  		cout<<"what arithmetics do you want to do with a and b? (+,-,*,/)\nenter ; to restart. please enter:";
	  		break;
	  	default:
	  		cout<<"enter wrong inputs. please try again.";
	  }	
    }
  }

    
    system("pause");
    return 0;
}
