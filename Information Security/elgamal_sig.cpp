/*
Elgamal Digital Signature
*/

#include<bits/stdc++.h>

using namespace std;

int sign(int m,int d,int n)
{
	long long result = 1;
	for(int i=0;i<d;i++)
	{
		result = ((((result)*(m))%n)+n)%n;
	}

	return (int)result;
}

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

int sign_aux(int m,int d,long long s1, int r, int p)
{
	long long s2;
	long long multi = (d*s1)%p;
	long long t1 = (((m-multi)%p)+p)%p;
	int t2 = mod_inverse(r,p);
	s2 = (t1*t2)%p;

	return (int)s2;
}

int verify(int e2,long long s1,long long s2, int p)
{
	int v2;
	int t1 = sign(e2,s1,p);
	int t2 = sign(s1,s2,p);
	v2 = (((t1%p*t2%p)%p)+p)%p;
	return int(v2);
}

int main()
{
	int p,e1,d;
	cout<<"p,e1,d:";
	cin>>p>>e1>>d;

	//Key Generation
	long long e2 = sign(e1,d,p);
	cout<<"e2:"<<e2<<endl;

	int r;
	cout<<"r:";
	cin>>r;
	int m;
	cout<<"Message:";
	cin>>m;

	//Signature
	int s1 = sign(e1,r,p);
	cout<<"s1:"<<s1<<endl;

	int s2 = sign_aux(m,d,s1,r,p-1);
	cout<<"s2:"<<s2<<endl;

	//Verification
	int v1 = sign(e1,m,p);
	cout<<"v1:"<<v1<<endl;

	int v2 = verify(e2,s1,s2,p);
	cout<<"v2:"<<v2<<endl;
}