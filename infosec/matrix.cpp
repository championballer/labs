/*
Matrix operations
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x1,y1;
	int x2,y2;

	cout<<"Enter dimension of first matrix:";
	cin>>x1>>y1;
	int ** A1 = new int*[x1];
	for(int i=0;i<x1;i++)
	{
		A1[i] = new int[y1];
		for(int j=0;j<y1;j++)
		{
			cin>>A1[i][j];
		}
	}

	for(int i=0;i<x1;i++)
	{
		for(int j=0;j<y1;j++)
		{
			cout<<A1[i][j]<<" ";
		}
		cout<<endl;
	}	
	cout<<"Enter dimension of second matrix:";
	cin>>x2>>y2;
	int ** A2 = new int*[x2];
	for(int i=0;i<x2;i++)
	{
		A2[i] = new int[y2];
		for(int j=0;j<y2;j++)
		{
			cin>>A2[i][j];
		}
	}

	for(int i=0;i<x2;i++)
	{
		for(int j=0;j<y2;j++)
		{
			cout<<A2[i][j]<<" ";
		}
		cout<<endl;
	}
	int ** A3;
	if(y1!=x2)return -1;

	 
	else
	{
		A3 = new int*[x1];	
		for(int i=0;i<x1;i++)
		{	
			A3[i] = new int[y2];
			for(int j=0;j<y2;j++)
			{
				int sum = 0;
				for(int k=0;k<y1;k++)
				{
					sum+=(A1[i][k]*A2[k][j]);
				}
				A3[i][j] = sum;
			}
		}	
	}

	for(int i=0;i<x1;i++)
	{
		for(int j=0;j<y2;j++)
		{
			cout<<A3[i][j]<<" ";
		}
		cout<<endl;
	}
	
}