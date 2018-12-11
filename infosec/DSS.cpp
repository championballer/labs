/*
Digital Signature Standard
*/

#include<bits/stdc++.h>

using namespace std;

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

int sign(int m,int d,int n,int q=0)
{
	long long result = 1;
	for(int i=0;i<d;i++)
	{
		result = ((((result)*(m))%n)+n)%n;
	}

	return (int)result;
}

int verify(int e1,int e2,int m_digest,int s1,int s2,int p,int q)
{
	int s2_inv = mod_inverse(s1,q);
	int pw1 = (m_digest*s2_inv)%q;
	int t1 = sign(e1,pw1,p);
	int pw2 = (s1*s2_inv)%q;
	int t2 = sign(e2,pw2,p);

	int v = ((t1*t2)%p)%q;

	return v;
}

int main()
{
	int p,q;
	int e0;
	cout<<"p,q,eo:";
	cin>>p>>q>>e0;
	int power = ((p-1)*mod_inverse(q,p))%p;
	int e1 = sign(e0,power,p);
	cout<<"e1:"<<e1<<endl;

	int d;
	cout<<"d:";
	cin>>d;

	int e2 = sign(e1,d,p);
	cout<<"e2:"<<e2<<endl;

	int m_digest;
	cout<<"message digest:";
	cin>>m_digest;

	int r;
	cout<<"r:";
	cin>>r;

	int s1;
	s1 = ((sign(e1,r,p,q))%q);
	cout<<"s1:"<<s1<<endl;

	int s2;
	s2 = (((m_digest+((d*s1)%q))%q)*(mod_inverse(r,q)))%q;
	cout<<"s2:"<<s2<<endl;

	int v;
	v = verify(e1,e2,m_digest,s1,s2,p,q);
	cout<<"v:"<<v<<endl;

}