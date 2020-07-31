#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
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
	   //cout<<"constructor 1"<<endl;
	}
	complex(float r)
	{
		this->real=this->imag=r;
		noofcomp++;
	   //cout<<"constructor 2"<<endl;
	}
	complex()
	{
		this->real=this->imag=0;
		noofcomp++;
	   //cout<<"constructor 3"<<endl;
	}
	complex(complex & c)
	{
		real=c.real;
		imag=c.imag;
	}
		~complex()
	{
		noofcomp--;
	   //cout<<"destructor..."<<endl;
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
	complex operator + (complex &c)
	{
		return complex(c.real+real,c.imag+imag);
	}
	complex operator + (float f)
	{
		return complex(real+f,imag);
	}
	complex operator ++() //pretfix
	{
		real++;
		imag++;
		return *this;
	}
	complex operator ++ (int dummy)//postfix
	{
		complex temp(*this);
		real++;
		imag++;
		return temp;
	}
	operator float()
	{
		return real;
	}
	complex operator = (complex & c)
	{
		real=c.real;
		imag=c.imag;
		return *this;
	}
	complex operator += (complex & c)
	{
		real=real+c.real;
		imag=imag+c.imag;
		return *this;
	}
	int operator < (complex & c)
	{
		return ((real<c.real)&&(imag<c.imag));
	}
	int operator == (complex & c)
	{
		return ((real==c.real)&&(imag==c.imag));
	}
	complex operator ()(float r,float i)
	{
		real=r;
		imag=i;
		return *this;
	}
	friend istream & operator >> (istream & ist,complex & c);
	friend ostream & operator << (ostream & ost,complex & c);
		void print_comp();
	friend complex operator +(float f, complex& c);
	friend void swapcomp(complex & c1,complex & c2);
};
complex operator +(float f,complex& c)
{
	return complex(f+c.real,c.imag);
}
istream & operator >> (istream & ist,complex & c)
	{
		cout<<"please Enter the real part ";
		ist>>c.real;
		cout<<endl<<"please Enter the imag part ";
		ist>>c.imag;
		cout<<endl;
		return	ist;
	}
ostream & operator << (ostream & ost,complex & c)
{
	ost<<" the result : "<<c.real;
	if(c.imag>0) ost<<"+i"<<c.imag;
	else  ost<<"-i"<<abs(c.imag);
	return ost;
}
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
complex c4(4.1,3.2);
int x=(c4==c1);
cout<<"c4==c1 "<<x<<endl;
c4=c1;
x=(c4==c1);
cout<<"c4==c1 "<<x<<endl;
float f=(float) complex(8.1,9.4);
cout<<"f=(float) complex(8.1,9.4) "<<f<<endl;
x= c4>c2;
cout<<"x= c4>c2 "<<x<<endl;
complex c5=(c4+c1);
cout<<"c5=c4+c1 ="<<c5<<endl;
c5+=c1;
cout<<"c5+=c1 "<<c5<<endl;
complex c6;
cin>>c6;
cout<<"c6 is "<<c6;
c6(3.8,4.5);
cout<<endl<<"c6 is "<<c6;
getch();
return 0;
}