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
void chinese_remainder(int a1,int a2,int m1,int m2)
{
	int M=m1*m2;
	int M1=M/m1,M2=M/m2;
	int invM1=findInverse(M1,m1);
	int invM2=findInverse(M2,m2);

	int x=(a1*M1*invM1 + a2*M2*invM2)%M;
	cout<<x<<" ";
}
int main()
{
	int P;
	cout<<"Plain Text: ";
	cin>>P;
	///KEY GENERATION-->
	///1. Select two large numbers p and q.
	int p=23,q=7;
	///2. n=pq
	int n=p*q;
	///3. Public Key: n, Private Key: p,q

	///ENCRYPTION-->
	int C=(P*P)%n;
	cout<<"Cipher Text: "<<C<<endl;

	///DECRYPTION-->
	int a1=modularExpo(C%p,(p+1)/4,p);
	int a2=p-a1;
	int b1=modularExpo(C%q,(q+1)/4,q);
	int b2=q-b1;

	chinese_remainder(a1,b1,p,q);
	chinese_remainder(a1,b2,p,q);
	chinese_remainder(a2,b1,p,q);
	chinese_remainder(a2,b2,p,q);
	cout<<"are the possible Plain Text"<<endl;
}