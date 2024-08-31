#include <iostream>
using namespace std;

int main() {
	
	int a, b, c; 
	
	cout<<"A SIMPLE DIVISION PROGRAM"<<endl<<endl<<endl; 
	cout<<"Enter the value of a and b: "<<endl; 
	cin>>a>>b;	
	try
	{
		if (b==0)
			{
			throw b;
			}
	c = a/b; 
	}	
		catch(int error)

	{
		cout<<"Error: b value shouldn't be zero "<<error;
	}

		cout<<"Division is: "<<c;
		return 0;
	}
