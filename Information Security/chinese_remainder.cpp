/*
Chinese Remainder
*/
#include<bits/stdc++.h>

using namespace std;

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
	//take input;
}