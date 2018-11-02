#include <bits/stdc++.h>
using namespace std;

int findInverse(int N,int M)
{
	N=N%M;
	int t1=0,t2=1,r1=M,r2=N;
	while(r2)
	{
		int q=r1/r2,r=r1%r2;
		r1=r2;
		r2=r;
		int t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	return (t1+M)%M;
}
int modularExpo(int X,int N,int M)
{
	if(N==0)
		return 1;
	if(N%2==0)
		return modularExpo((X*X)%M,N/2,M);
	return (X*modularExpo(X,N-1,M))%M;
}
int main()
{
	int P;
	cout<<"Plain Text: ";
	cin>>P;
	///KEY GENERATION-->
	///1. Take a big prime number p
	int p=11;
	///2. Decide a d such that 1<=d<=p-2
	int d=3;
	///3. Find e1 such that e1 is primitive root of p
	///Primitive root means if x^n = y, n>=1 AND n<p, then y should cover all numbers 1 to p-1
	int e1=2;
	while(e1<p)
	{
		bool h[p];
		for(int i=1;i<p;i++)
			h[i]=0;
		for(int i=e1,j=1;j<p;j++,i=(i*e1)%p)
			h[i]=1;
		bool flag=true;
		for(int i=1;i<p;i++)
			if(!h[i])
			{
				flag=false;
				break;
			}
		if(flag)
			break;
		e1++;
	} 
	///4. Find e2=(e1^d)%p
	int e2=modularExpo(e1%p,d,p);
	///5. Public Key: e1,e2,p Private Key: d,p


	///ENCRYPTION-->
	///Find a random number r
	int r=4;
	int C1=modularExpo(e1%p,r,p);
	int C2=(P*modularExpo(e2%p,r,p))%p;
	cout<<"Cipher Text: "<<C1<<" and "<<C2<<endl;

	///DECRYPTION-->
	P=(C2*findInverse(modularExpo(C1,d,p),p))%p;
	cout<<"Plain Text: "<<P<<endl;

}