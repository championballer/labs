/*
Elliptic curve cryptography using GF(p)
*/

#include<bits/stdc++.h>

using namespace std;

struct point{
	int x;
	int y;
};

int mod_inverse(int x, int m)
{
	int r1 = m;
	int r2 = x;
	int r = 0;
	int t1 = 0;
	int t2 = 1;
	int t = 0;
	int q = 0;
	while(r2!=0)
	{
		q = int(r1/r2);
		r = r1%r2;
		t = t1 - q*t2;
		r1 = r2;
		r2 = r;
		t1 = t2;
		t2 = t;
	}

	if(r1!=1)
	{
		//throw error and exit program
	}

	return (t1%m+m)%m;
}


int slope(point p1,point p2,int p)
{
	int d_y = (((p2.y-p1.y)%p)+p)%p;
	int d_x = (((p2.x-p1.x)%p)+p)%p;
	int result = (d_y * mod_inverse(d_x,p))%p;
	return result;
}

int slope_d(point p1,int a,int p)
{
	int x1 = p1.x;
	int x1_2 = (x1*x1)%p;
	
	int x = (3*x1_2)%p;
	
	int t1 = (((x+a)%p)+p)%p;
	
	int par1 = (2*p1.y)%p;
	int t2 = mod_inverse(par1,p);
	
	int result = ((t1)*(t2))%p;
	return result;
}

point add_same(point p1,int a,int p)
{
	int s = slope_d(p1,a,p);
	point p_result;
	int s_2 = (s*s)%p;
	p_result.x = (((s_2-p1.x-p1.x)%p)+p)%p;
	int x_d = (((p1.x - p_result.x)%p)+p)%p;
	int t1 = (s*(x_d)%p);
	p_result.y = (((t1-p1.y)%p)+p)%p;
	return p_result;
}

point add_diff(point p1,point p2,int p)
{
	int s = slope(p1,p2,p);
	point p_result;
	int s_2 = (s*s)%p;
	p_result.x = (((s_2-p1.x-p2.x)%p)+p)%p;
	int x_d = (((p1.x - p_result.x)%p)+p)%p;
	int t1 = (s*(x_d)%p);
	p_result.y = (((t1-p1.y)%p)+p)%p;
	return p_result;	
}


point unit(point p1,point p2,int a, int p)
{
	if(p1.x==p2.x and p1.y==p2.y)
	{
		return add_same(p1,a,p); 
	}

	else return add_diff(p1,p2,p);
}


int main()
{

	int a,b;
	int p;
	int d;
	point p1;
	point p2;
	cin>>a>>p>>d>>p1.x>>p1.y;
	p2.x = p1.x;
	p2.y = p1.y;
	for(int i=0;i<d-1;i++)
	{
		p2 = unit(p1,p2,a,p);
	}

	cout<<p2.x<<" "<<p2.y<<endl;
	

	
	
	
}