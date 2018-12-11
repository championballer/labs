/*
RSA Signature 
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

long long sign(int m,int d,int n)
{
	long long result = 1;
	for(int i=0;i<d;i++)
	{
		result = ((((result)*(m))%n)+n)%n;
	}

	return result;
}

int main()
{
	int p,q,n;
	cout<<"p,q:";
	cin>>p>>q;


	n = p*q;
	cout<<"n:"<<n<<endl;
	int tot = (p-1)*(q-1);
	cout<<"totient:"<<tot<<endl;
	cout<<"e:";
	int e;
	cin>>e;

	int d = mod_inverse(e,tot);
	cout<<"d:"<<d<<endl;

	cout<<"M:";
	int m;
	cin>>m;

	long long s = sign(m,d,n);
	cout<<"s:"<<s<<endl;
	long long m_d = sign(s,e,n);
	cout<<"m:"<<m_d<<endl;
	

}