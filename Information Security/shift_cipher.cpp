
///Encryption with g(N)=f(N)+2

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cout<<"Please enter the no. of test cases:";
	cin>>T;
	int K=2;
	while(T--)
	{
		string input,output;
		cout<<"Message: ";
		cin>>input;
		
		///ENCRYPTION
		cout<<"Encrypted Data: ";
		for(int i=0;i<input.size();i++)
			output+=(input[i]-'a'+K)%26+'a';
		cout<<output<<endl;

		///DECRYPTION
		cout<<"Descrypted Data: ";
		input.clear();
		for(int i=0;i<output.size();i++)
			input+=(output[i]-'a'-2+26)%26+'a';
		cout<<input<<endl;
	}
}