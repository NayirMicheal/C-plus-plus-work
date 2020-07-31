#include<iostream.h>
#include<stdio.h>
struct complex
{
	private:
	float real,imag;
	public:
	void setReal(float r)
	{
		real=r;
	}
	void setImag(float i)
	{
		imag=i;
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
	void print_comp()
	{
	cout<<real<<" + i "<<imag;
	}
	
};
int main()
{
complex c1,c2;
clrscr();
c1.setReal(5.1);
c1.setImag(2.2);
c2.setAll(2.9,4.3);
c1.print_comp();
c2.print_comp();
}