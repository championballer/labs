#include<iostream>

using namespace std;

int main()
{

	int data[11];
	cout<<"Please enter the 7 bits one by one"<<endl;
	cin>>data[10];
	cin>>data[9];
	cin>>data[8];
	cin>>data[6];
	cin>>data[5];
	cin>>data[4];
	cin>>data[2];
	
	data[0]=(data[2]+data[4]+data[6]+data[8]+data[10])%2;
	data[1]=(data[2]+data[5]+data[6]+data[9]+data[10])%2;
	data[3]=(data[4]+data[5]+data[6])%2;
	data[7]=(data[8]+data[9]+data[10])%2;
	cout<<"Data encoded:";
	for(int i =10;i>=0;i--)
	cout<<data[i]<<" ";
	cout<<endl;

	int check[11];
	cout<<"Please enter data received at receiver:"<<endl;
	for(int i=10;i>=0;i--)
	cin>>check[i];
	int flag=0;
	int index=0;
	int error[4];
	error[0]=(check[0]+check[2]+check[4]+check[6]+check[8]+check[10])%2;
	error[1]=(check[1]+check[2]+check[5]+check[6]+check[9]+check[10])%2;
	error[2]=(check[3]+check[4]+check[5]+check[6])%2;
	error[3]=(check[7]+check[8]+check[9]+check[10])%2;
	int errorloc = error[3]*8+error[2]*4+error[1]*2+error[0]*1;
	if(errorloc==0)
	{
		cout<<"No error"<<endl;
	}
	
	else 
	{
		cout<<"Error detected"<<endl;
	}
	
	
}
