#include <iostream>
using namespace std;

struct Point
{
	double x,y;
	// 构造函数 
	Point(){}
	Point(double x,double y):x(x),y(y){}
};

struct Rec
{
	Point A,B;
};

int min(int x,int y)
{
	return (x)<(y)?(x):(y);
}

int max(int x,int y)
{
	return (x)>(y)?(x):(y);
}

// 判断叉乘 
double direction(Point p_0, Point p_1, Point p_2)
{
    Point p1(p_2.x - p_0.x, p_2.y - p_0.y);
    Point p2(p_1.x - p_0.x, p_1.y - p_0.y);
    return (p1.x*p2.y-p2.x*p1.y);
}

// 快速排斥 
bool quick_check(Point A, Point B,Point C,Point D)
{
	Rec R,T,F;
	R.A.x=min(A.x,B.x);
	R.A.y=min(A.y,B.y);
	R.B.x=max(A.x,B.x);
	R.B.y=max(A.y,B.y);
	
	T.A.x=min(C.x,D.x);
	T.A.y=min(C.y,D.y);
	T.B.x=max(C.x,D.x);
	T.B.y=max(C.y,D.y);
	
	F.A.x=max(R.A.x,T.A.x); 
	F.A.y=max(R.A.y,T.A.y);
	F.B.x=min(R.B.x,T.B.x); 
	F.B.y=min(R.B.y,T.B.y);
	
	if(F.A.x>=F.B.x || F.A.y>=F.B.y)
		return false;
	return true;
		
} 

// 跨立实验 
bool cross(Point A, Point B,Point C,Point D)
{	
	if(!quick_check(A,B,C,D)) 
		return false;
		
	if(direction(A,B,C)*direction(A,B,D)>=0) 
		return false;
    if(direction(C,D,A)*direction(C,D,B)>=0) 
		return false;
	
	return true;	
}

int main()
{
	Point A,B,C,D;
	cout<<"请输入第一条线段的两个端点：";
	cin>>A.x>>A.y>>B.x>>B.y;
	cout<<"请输入第二条线段的两个端点：";
	cin>>C.x>>C.y>>D.x>>D.y;

	
	if(!quick_check(A,B,C,D))
		cout<<"矩阵R与T矩阵不相交 即线段AB与线段CD不相交"<<endl;
	else
	{
		if(cross(A,B,C,D))
			cout<<"线段AB与 线段CD相交"<<endl;
		else
			cout<<"不相交"<<endl; 
	} 
	return 0;
}
