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

	return (t1%m+m)%m;
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

int pow(int n,int x,int p)
{
	int result = 1;
	for(int i=0;i<x;i++)
	{
		result = (result*n)%p;
	}

	return result;
}
bool check(point p1,int a, int b,int p)
{
	int to_check = ((pow(p1.x,3,p))+((a*p1.x)%p)+b)%p;
	int power  = (p-1)/2;
	int c1 = pow(to_check,power,p);
	
	if(c1==1)
	{
		return true;
	}

	else return false;
}

int main()
{
	int a,b,p;
	cout<<"Please enter a,b,p:";
	cin>>a>>b>>p;

	point p1;
	cout<<"Please enter point to check:";
	cin>>p1.x>>p1.y;

	if(check(p1,a,b,p))
	{
		point aux;
		aux = add_same(p1,a,p);

		cout<<"Added point:"<<aux.x<<" "<<aux.y<<endl;;	
	}

	else
	{
		cout<<"Not on curve"<<endl;
	}
	}