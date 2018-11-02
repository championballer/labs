#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cout<<"Please enter the no. of testcases:";
	cin>>t;

	while(t--)
	{
		string plain;
		cout<<"Enter plain text:";
		cin>>plain;
		
		string key;
		cout<<"Enter key:";
		cin>>key;

		for(int i=0,j=0;i<plain.length();i++)
		{
			plain[i]=(plain[i]-97+key[j]-97)%26+97;
			j = (j+1)%key.length();

		}

		cout<<plain<<endl;
	}
}