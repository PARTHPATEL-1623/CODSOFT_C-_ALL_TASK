#include<iostream>
using namespace std;


class calculater
{
	public:
		void choice(int,int);
};

void calculater::choice(int a,int b)
{
	
	int ch;
	cout<<endl;
	cout<<" ENTER THE CHOICE --> ";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			cout<<endl;
			cout<<"--- ADDITION --> " << a + b <<endl;
			break;
			
		case 2:
			cout<<endl;
			cout<<"--- SUBTRACTION --> " << a - b <<endl;
			break;
			
			
		case 3:
			cout<<endl;
			cout<<"--- MULTIPLICATION --> " << a * b <<endl;
			break;
			
			
		case 4:
			cout<<endl;
			cout<<"--- DIVISION --> " << a / b <<endl;
			break;
			
			
		case 5:
			cout<<endl;
			cout<<"--- MODULO --> " << a % b <<endl;
			break;
			
		default:
		    cout<<endl;
			cout<<" !!! ENTER VALID CHOICE !!! ";
			break;	
			
			
	}
}
 
int main()
{
    int a,b;
	system("cls");
	calculater c;
	
	cout<<endl;
	cout<<" ENTER THE VALUE OF A --> ";
	cin>>a;
	
	cout<<endl;
	cout<<" ENTER THE VALUE OF B --> ";
	cin>>b;
	
	c.choice(a,b);	
}
