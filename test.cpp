#include<iostream>
#include<cmath>
using namespace std;
class Polar
{
private:
	float r, a;
public:
	Polar(float radius, float angle)
	{
		r=radius;
		a=angle;
	}
	Polar(){}
	Polar operator +(Polar &p)
	{
		Polar temp;
		float x=r*cos(a)+p.r*cos(p.a);
		float y=r*sin(a)+p.r*sin(p.a);
		temp.r=sqrt(x*x+y*y);
		temp.a=atan2(y, x);
		return temp;
	}
	void display()
	{
		cout<<"The coordinate is: ("<<r<<","<<a<<")"<<endl;
	}
};

int main()
{
	Polar p1(5, 60), p2(4, 60), p3;
	p3=p1+p2;
	p3.display();
	return 0;
}