#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class geoshape{
	protected:
	float dim1,dim2;
	public:
	geoshape(){}

	geoshape(float d1,float d2)
	{
		dim1=d1;
		dim2=d2;
	}
	geoshape(float d)
	{
		dim1=dim2=d;
	}
	void setDim1(float d1)
	{
		dim1=d1;
	}
	void setDim2(float d2)
	{
		dim2=d2;
	}
	float getDim1()
	{
		return dim1;
	}
	float getDim2()
	{
		return dim2;
	}
	float calcarea()
	{
		return dim1*dim2;
	}
};
class Triangle:public geoshape
{
	public:
	Triangle()
	{

	}
	Triangle(float h,float b)
	{
		dim1=h;
		dim2=b;
	}

	float calcarea()
	{
		return dim1*dim2*.5;
	}
};
class Rect:public geoshape
{
	public:
	Rect(float w,float h)
	{
		dim1=w;
		dim2=h;
	}
	Rect(){}
	float calcarea()
	{
		return dim1*dim2;
	}
};
class Square:public Rect
{
	public:
	Square(float L)
	{
		dim1=dim2=L;
	}
	Square(){}
	/*if the inhertance is protected we must override
	to be able to call the function from main*/


	void setDim1(float f)
	{
		dim1=dim2=f;
	}
	void setDim2(float f)
	{
		dim1=dim2=f;
	}


};
class Circle:public geoshape
{
	public:
	Circle(float r)
	{
		dim1=dim2=r;
	}
	void setDim1(float r)
	{
		dim1=dim2=r;
	}
	void setDim2(float r)
	{
		dim1=dim2=r;
	}
	float calcarea()
	{
	  return 3.14*dim1*dim2;
	}

};
int main()
{       clrscr();
	Triangle t1(10,20);
	cout<<"Triangle "<<t1.calcarea()<<endl;
	Circle c1(50);
	cout<<"Rect "<<c1.calcarea()<<endl;
	Rect r1(10,20);
	cout<<"Rect "<<r1.calcarea()<<endl;
	Square s1(20);
	cout<<"Square "<<s1.calcarea()<<endl;
	getch();
	return 0;
}