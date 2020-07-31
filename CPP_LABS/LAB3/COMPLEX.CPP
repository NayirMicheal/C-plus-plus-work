#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class complex
{
	private:
	float real,imag;
	static int noofcomp;
	public:
	complex(float real,float imag)
	{
		this->real=real;
		this->imag=imag;
		noofcomp++;
		cout<<"constructor 1"<<endl;
	}
	complex(float r)
	{
		this->real=this->imag=r;
		noofcomp++;
		cout<<"constructor 2"<<endl;
	}
	complex()
	{
		this->real=this->imag=0;
		noofcomp++;
		cout<<"constructor 3"<<endl;
	}
		~complex()
	{
		noofcomp--;
		cout<<"destructor..."<<endl;
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
	static int getnoofcomplex()
	{
		return noofcomp;
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
int complex::noofcomp=0; //init of static var
int main()
{
clrscr();
complex c1(5.2,1.2);
cout<<"no of complex numbers is "<<complex::getnoofcomplex()<<endl;
complex c2(9);
complex c3;
cout<<"no of complex numbers is "<<complex::getnoofcomplex()<<endl;
c3.setReal(5.1);
c3.setImag(2.2);
c2.setAll(2.9,4.3);
cout<<"c1 is ";
c1.print_comp();
cout<<"c2 is ";
c2.print_comp();
cout<<"c3 is ";
c3.print_comp();
swapcomp(c1,c2);
cout<<endl;
cout<<"c1 is ";
c1.print_comp();
cout<<"c2 is ";
c2.print_comp();
getch();
return 0;
}