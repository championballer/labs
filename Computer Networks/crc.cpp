#include<bits/stdc++.h>

using namespace std;

void leftShift(int * key, int size)
{
	for(int i=0;i<size-1;i++)
	{
		key[i]=key[i+1];
	}
}

int main()
{
	int nkey;
	cout<<"Please enter the number of bits in key:";
	cin>>nkey;
	
	int * key = new int[nkey];
	for(int i=0;i<nkey;i++)
	{
		cin>>key[i];
	}

	int ndatas;
	cout<<"Please enter the number of bits in data:";
	cin>>ndatas;
	int * data = new int[ndatas+nkey-1];
	memset(data,0,sizeof(int)*ndatas+nkey-1);
	for(int i=0;i<ndatas;i++)
	{
	cin>>data[i];
	}
	
	for(int i=0;i<ndatas+nkey-1;i++)
	{
	cout<<data[i];
	}

	cout<<endl;

	int * rem = new int[nkey];
	memset(rem,0,sizeof(int)*nkey);
	for(int i=0;i<nkey;i++)
	{
		rem[i]=data[i];
	}

	for(int i=0;i<nkey;i++)
	{
		rem[i]=rem[i]^key[i];
	}
	
	for(int i=nkey;i<ndatas+nkey-1;i++)
	{
		leftShift(rem,nkey);
		
		rem[nkey-1]=data[i];
		for(int k=0;k<nkey;k++)
		{
			cout<<rem[k];
		}
	
		cout<<endl;
		if(rem[0]==1)
		{
			for(int j=0;j<nkey;j++)
			{
			rem[j]=rem[j]^key[j];
			}
		}
			
	
	}

	for(int i=0;i<nkey;i++)
	{
		cout<<rem[i];
	}
	
	cout<<endl;
	
	for(int i=0;i<nkey-1;i++)
	{
		data[ndatas+i]=data[ndatas+i]+rem[i+1];
		
	}

	for(int i=0;i<ndatas+nkey-1;i++)
	{
	cout<<data[i];
	}	
		
	int ndatar;
	cout<<"Please enter the bits in receiver:";
	cin>>ndatar;
	int * rec = new int[ndatar];
	for(int i=0;i<ndatar;i++)
	{
		cin>>rec[i];
	}

	int * rem2 = new int[nkey];
	memset(rem2,0,sizeof(int)*nkey);
	for(int i=0;i<nkey;i++)
	{
		rem2[i]=data[i];
	}

	for(int i=0;i<nkey;i++)
	{
		rem2[i]=rem2[i]^key[i];
	}
	
	for(int i=nkey;i<ndatas+nkey-1;i++)
	{
		leftShift(rem2,nkey);
		
		rem2[nkey-1]=data[i];
		for(int k=0;k<nkey;k++)
		{
			cout<<rem2[k];
		}
	
		cout<<endl;
		if(rem2[0]==1)
		{
			for(int j=0;j<nkey;j++)
			{
			rem2[j]=rem2[j]^key[j];
			}
		}
			
	
	}

	for(int i=0;i<nkey;i++)
	{
		cout<<rem2[i];
	}
	
	cout<<endl;
		
	
}
