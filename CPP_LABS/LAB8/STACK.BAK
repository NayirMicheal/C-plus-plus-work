#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class complex
{
	private:
	float real,imag;
	public:
	complex(float real,float imag)
	{
		this->real=real;
		this->imag=imag;
	}
	complex(float r)
	{
		this->real=this->imag=r;
	}
	complex()
	{
		this->real=this->imag=0;
	}
		~complex()
	{
	}
	void setReal(float r)
	{
	   this->real=r;
	}
	void setImag(float i)
	{
	   this->imag=i;
	}
	void setAll(float r,float i)
	{
		real=r;
		imag=i;
	}
	float getReal()
	{
		return real;
	}
	float getImag()
	{
		return imag;
	}
	void print_comp();
	friend void swapcomp(complex & c1,complex & c2);
};
void complex::print_comp() //write a function outside the class
{
	cout<<real<<" + i "<<imag<<endl;
}
void swapcomp(complex & c1,complex & c2)
{
	float r_temp,i_temp;
	r_temp=c1.real;
	i_temp=c1.imag;
	c1.real=c2.real;
	c1.imag=c2.imag;
	c2.real=r_temp;
	c2.imag=i_temp;
}

template <class T>
class stack
{
	int tos,size;
	T* stk;
	static int counter;
	public:
	stack()
	{
		tos=0;
		size=10;
		stk=new T[size];
		counter++;
	}
	~stack()
	{
		delete [] stk;
		counter--;
	}
	stack(int s)
	{
		tos=0;
		size=s;
		stk=new T[size];
		counter++;
	}
	int isFull()
	{
		return tos==size;
	}
	int isEmpty()
	{
		return tos==0;
	}
	stack(stack & s);
	int pop(T & data);
	int push(T data);
	stack & operator = (stack & s);
	static int getCounter()
	{
		return  counter;
	}
};
template <class T>
stack<T>:: stack(stack<T> & s)
{
	tos=s.tos;
	size=s.size;
	stk=new T[size];
	for(int i=0;i<tos;i++)
	{
		stk[i]=s.stk[i];
	}
	counter++;
}

template <class T>
int stack<T>:: push(T data)
{
	if(isFull())
		return 0;
	stk[tos]=data;
	tos++;
	return 1;
}
template <class T>
int stack<T>::pop(T & data)
{
	if(isEmpty())
		return 0;
	tos--;
	data=stk[tos];
	return 1;
}

template <class T>
stack<T> & stack<T>:: operator =(stack<T> & s)
{
	delete [] stk;
	tos=s.tos;
	size=s.size;
	stk=new T[size];
	for(int i=0;i<tos;i++)
		stk[i]=s.stk[i];
	return *this;
}
template <class T>
stack<T>:: counter=0;
int main()
{
	clrscr();
	stack<int> s1(7);
	stack <float> s2(20);
	stack <complex> s3;
	stack <int> s4,s5;

	s1.push(5);
	s2.push(33.3);
	s3.push(complex(2.1,5.5));
	cout<<s1.getCounter()<<endl;
	cout<<s2.getCounter()<<endl;
	cout<<s3.getCounter()<<endl;
	getch();
	return 0;
}