
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
	if(a==0 && b==0)return 0;
	if(b>a)return gcd(b,a);
	if(b==0)return a;

	return gcd(b,a%b);
}
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
	cout<<"Enter Plain text: ";
	cin>>P;
	///KEY GENERATION-->

	///1. CHOOSE TWO PRIMES p and q
	int p=7,q=11;
	///2. n=pq
	int n=p*q;
	///3. choose e such that gcd(e,Q(n))=1.
	int e=2;
	int Qn=(p-1)*(q-1);
	while(gcd(e,Qn)!=1 && e<Qn)
		e++;
	///4. d=inverse(e) mod Qn
	int d=findInverse(e,Qn);
	///5.Public Key=e, Private key=d

	///ENCRYPTION-->
	int C=modularExpo(P%n,e,n);
	cout<<"Cipher Text: "<<C<<endl;

	///DECRYPTION-->
	P=modularExpo(C%n,d,n);
	cout<<"Plain Text: "<<P<<endl; 



}