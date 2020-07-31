#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class point
{
int x,y;
public:
point ()
{
x=y=0;
}
point(int a,int b)
{
	x=a;
	y=b;
}
point(point& p)
{
	x=p.x;
	y=p.y;
}
point (int a)
{
	x=y=a;
}
~point ()
{
cout<<"point destructor"<<endl;
}
point operator =(point & p)
{
	x=p.x;
	y=p.y;
	return *this;
}
void setX(int a)
{
x=a;
}
void setY(int b)
{
y=b;
}
void setAll(int a,int b)
{
	x=a;
	y=b;
}
int getX()
{
	return x;
}
int getY()
{
	return y;
}
void print()
{
	cout<<" is: "<<"x="<<x<<" "<<"y="<<y<<endl;
}
};
class Line
{
	point p1,p2;
	public:
	Line():p1(5,5),p2(10,10)
	{

	}
	Line(int x1,int y1,int x2,int y2):p1(x1,y1),p2(x2,y2)
	{

	}
	Line(point ps,point pe):p1(ps),p2(pe)
	{

	}
	~ Line()
	{
	cout<<"Line destructor"<<endl;
	}
	void setp1(point ps)
	{
		p1.setX(ps.getX());
		p1.setY(ps.getY());
	}
	void setp2(point pe)
	{
		p2.setX(pe.getX());
		p2.setY(pe.getY());
	}
	point getP1()
	{
		return p1;
	}
	point getP2()
	{
		return p2;
	}
	void printLine()
	{
		cout<<"---Line---"<<endl;
		cout<<"Start point";
		p1.print();
		cout<<"End Point";
		p2.print();
	}
};
class CIRCLE
{
	point center;
	int radius;
	public:
	CIRCLE():center(50,50),radius(10)
	{
		cout<<"def cons CIRCLE"<<endl;
	}
	CIRCLE(int x,int y,int r):center(x,y)
	{
		radius=r;
		cout<<"cons CIRCLE x,y,r"<<endl;
	}
	CIRCLE(point p,int r):center(p)
	{
		cout<<"cons CIRCLE p,r"<<endl;
		radius=r;
	}
	CIRCLE(int a,int r):center(a),radius(r)
	{
		cout<<"cons CIRCLE a,r"<<endl;
	}
	~CIRCLE()
	{
		cout<<"CIRCLE destructor"<<endl;
	}
	void setCenter(point p)
	{
		center.setX(p.getX());
		center.setY(p.getY());
	}
	void setCenter(int a,int b)
	{
		center.setX(a);
		center.setY(b);
	}
	void setRadius(int r)
	{
		radius=r;
	}
	int getRadius()
	{
		return radius;
	}
	point getcenter()
	{
		return center;
	}
	void printCIRCLE()
	{
		cout<<"Center";
		center.print();
		cout<<"Radius="<<radius<<endl;
	}
};
class Rect
{
	point ul,lr;
	public:
	Rect():ul(5,5),lr(10,10)
	{
		cout<<"def cons Rect"<<endl;
	}
	Rect(point a,point b):ul(a),lr(b)
	{
		cout<<"cons Rect point a,b"<<endl;
	}
	Rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
	{
		cout<<"cons Rect x1,y1,x2,y2"<<endl;
	}
	~Rect()
	{
		cout<<"Rect destructor"<<endl;
	}
	void setUL(point p)
	{
		ul.setX(p.getX());
		ul.setY(p.getY());
	}
	void setUL(int a,int b)
	{
		ul.setX(a);
		ul.setY(b);
	}
	void setLR(point p)
	{
		lr.setX(p.getX());
		lr.setY(p.getY());
	}
	void setLR(int a,int b)
	{
		lr.setX(a);
		lr.setY(b);
	}
	point getUL()
	{
		return ul;
	}
	point getLR()
	{
		return lr;
	}
	void printRect()
	{
		cout<<"Upper left";
		ul.print();
		cout<<"Lower right";
		lr.print();
	}
};
class Picture
{
int NL,NC,NR;
Line * L;
CIRCLE * C;
Rect * R;
public:
Picture()
{

}
//Picture(int LL,int CC,int RR,Line * pl,CIRCLE * pc,Rect * pr); //strong

Picture(int LL,int CC,int RR,Line * pl,CIRCLE * pc,Rect * pr) //Weak
{
	NL=LL;
	NC=CC;
	NR=RR;
	L=pl;
	C=pc;
	R=pr;
}

Picture(Picture & pic); //copy constructor
void Draw();

/*
~Picture() //strong
{
if(L) delete [] L;
if(C) delete [] C;
if(R) delete [] R;
} */


~Picture() //weak
{
NL=NR=NC=0;
L=NULL;
C=NULL;
R=NULL;
}

//void setLines(int LL,Line * pl); //strong
//void setCircles(int CC,CIRCLE * pc); //strong
//void setRects(int RR,Rect * pr); //strong

void setLines(int LL,Line * pl) //weak
{
	NL=LL;
	L=pl;
}
void setCircles(int CC,CIRCLE * pc) //weak
{
	NC=CC;
	C=pc;
}
void setRects(int RR,Rect * pr) //weak
{
	NR=RR;
	R=pr;
}

Line * getLines()
{
	return L;
}
CIRCLE * getCircles()
{
	return C;
}
Rect * getRects()
{
	return R;
}
};
  /*
Picture :: Picture(int LL,int CC,int RR,Line * pl,CIRCLE * pc,Rect * pr) //strong
{
	NL=LL;
	NC=CC;
	NR=RR;
	L=new Line[NL];
	C=new CIRCLE[NC];
	R=new Rect[NR];
	for(int i=0;i<NL;i++)
		L[i]=pl[i];
	for(i=0;i<NC;i++)
		C[i]=pc[i];
	for(i=0;i<NR;i++)
		R[i]=pr[i];
}
 */
Picture::Picture(Picture & pic) //copy constructor
{
	NL=pic.NL;
	NC=pic.NC;
	NR=pic.NR;
	L=new Line[NL];
	C=new CIRCLE[NC];
	R=new Rect[NR];
	for(int i=0;i<NL;i++)
		L[i]=pic.L[i];
	for(i=0;i<NC;i++)
		C[i]=pic.C[i];
	for(i=0;i<NR;i++)
		R[i]=pic.R[i];
}
void Picture:: Draw()
{
	for(int i=0;i<NL;i++)
		L[i].printLine();
	for(i=0;i<NC;i++)
		C[i].printCIRCLE();
	for(i=0;i<NR;i++)
		R[i].printRect();
}
  /*
void Picture::setLines(int LL,Line * pl) //strong
{
	if(L)
	delete [] L;
	NL=LL;
	L=new Line[LL];
	for(int i=0;i<LL;i++)
		L[i]=pl[i];
}
void Picture:: setCircles(int CC,CIRCLE * pc) //strong
{
	if(C)
	delete [] C;
	NC=CC;
	C=new CIRCLE[CC];
	for(int i=0;i<CC;i++)
		C[i]=pc[i];
}
void Picture:: setRects(int RR,Rect * pr) //strong
{
	if(R)
	delete [] R;
	NR=RR;
	R=new Rect[RR];
	for(int i=0;i<RR;i++)
		R[i]=pr[i];
}
*/
int main ()
{
	clrscr();
	Line LL [2]={Line(point (5,9),point (10,9)),Line(4,8,7,9)};
	CIRCLE CC[2]={CIRCLE(11,25,11),CIRCLE(point(44,22),9)};
	Rect RR[2]={Rect(point(66,94),point(12,14)),Rect(74,95,42,66)};
	Picture pic (2,2,2,LL,CC,RR);
	CIRCLE CC2[2]={CIRCLE(45,45,45),CIRCLE(66,66,66)};
	pic.setCircles(2,CC2);
	pic.Draw();
	getch();
	return 0;
}