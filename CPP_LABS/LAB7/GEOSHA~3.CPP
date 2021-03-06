#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class geoshape{
	protected:
	float dim1,dim2;
	public:
	geoshape(float d1,float d2)
	{
		dim1=d1;
		dim2=d2;
	}
	geoshape()
	{
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
virtual	float calcarea()=0;

};
class Triangle:public geoshape
{
	public:
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
	Rect()
	{
	}
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
	Square()
	{
	}
	/*if the inhertance is protected we must override
	to be able to call the function from main*/

	/*
	void setDim1(float f)
	{
		dim1=dim2=f;
	}
	void setDim2(float f)
	{
		dim1=dim2=f;
	}
	*/
	void setSquareLength(float l)
	{
		dim1=dim2=l;
	}
};
class Circle:public geoshape
{
	public:
	Circle(float r)
	{
		dim1=dim2=r;
	}
	float calcarea()
	{
	 return	3.14*dim1*dim2;
	}
	void setRadius(float r)
	{
		dim1=dim2=r;
	}
};
float sumAreas(geoshape * p1,geoshape * p2,geoshape * p3)
{
	return p1->calcarea()+p2->calcarea()+p3->calcarea();
}
int main()
{
	clrscr();
	Circle c1(5),c2(9),c3(8);
	Triangle t1(5,9),t2(7,8),t3(12,11);
	Square s1(6),s2(9),s3(11);
	Rect r1(14,43),r2(22,21),r3(25,75);
	geoshape * gptr=&c1;
	geoshape * gpptr=new Square[5];
	gpptr=&c2;
   cout<< "gpptr=&c2 //calcarea for c2 "<<	gpptr->calcarea()<<endl;
   //	gptr->setRadius(7); //error not found cause gptr can found only members in geoshape
	cout<<"gptr->calcarea()"<<gptr->calcarea()<<endl; //try one time virtual and another not virtual


	cout<<"s1+r1+t1 ="<<sumAreas(&t1,&r1,&s1)<<endl;
	cout<<"t2+c1+s2 ="<<sumAreas(&t2,&c1,&s2)<<endl;
	cout<<"r3+r2+s3 ="<<sumAreas(&r3,&r2,&s3)<<endl;
	getch();
	return 0;
}