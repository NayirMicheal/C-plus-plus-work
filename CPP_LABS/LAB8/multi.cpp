#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class base1
{
	public:
	int x;
	
	int Hello()
	{
	cout<<"Hello from Base 1"<<end	
	}
};
class base2
{
	public:
	int x;
	
	int Hello()
	{
	cout<<"Hello from Base 2"<<end	
	}
};
class derived:public base1,base2
{
	
};

int main()
{
	derived d1;
	cout<<d1.Hello()<<endl;
	getch();
	return 0;
}