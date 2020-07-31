#include<iostream.h>
#include<conio.h>
class stack
{
private:
int tos,size;
int * stk;
static int noofstacks;
public:	
stack()
{
	this->tos=0;
	this->size=10;
	this->stk=new int[this->size];
	noofstacks++;
	cout<<"con 1"<<endl;
}
stack(int size)
{
	this->tos=0;
	this->size=size;
	this->stk=new int[this->size];
	noofstacks++;
	cout<<"con 2"<<endl;
}
stack(stack & s)
{
	tos=s.tos;
	size=s.size;
	stk=new int[size];
	for(int i=0;i<tos;i++)
		stk[i]=s.stk[i];
	cout<<"copy constructor"<<endl;
}
~stack()
{
	this->tos=0;
	this->size=0;
	delete [] this->stk;
	noofstacks--;
	cout<<"destructor: no of stacks "<<noofstacks<<endl;
}
int isFull();
int isEmpty();
int push(int data);
int pop(int & data);
friend void printstack(stack s);
static int getnoofstacks();
};
void printstack(stack s)
{
	cout<<"the printed stack "<<endl;
	for(int i=0;i<s.tos;i++)
		cout<<s.stk[i]<<endl;
}
int stack::noofstacks=0;
int main()
{
	int data;
	stack s1(7),s2;
	cout<<"No of stacks "<<stack::getnoofstacks()<<endl;
	stack s3(4);
	cout<<"No of stacks "<<stack::getnoofstacks()<<endl;
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s1.push(10);
	printstack(s1);
	s1.pop(data);
	cout<<"the poped data is "<<data<<endl;
	s1.pop(data);
	cout<<"the poped data is "<<data<<endl;
	printstack(s1);
	getch();
	return 0;	
}
int stack::getnoofstacks()
{
	return noofstacks;
}
int stack::isFull()
{
	return this->tos==this->size;
}
int stack::isEmpty()
{
	return this->tos==0;
}
int stack::push(int data)
{
	if(this->isFull())
		return 0;
	this->stk[this->tos]=data;
	this->tos++;
	return 1;
}
int stack::pop(int & data)
{
	if(this->isEmpty())
		return 0;
	data=this->stk[--this->tos];
	return 1;
}