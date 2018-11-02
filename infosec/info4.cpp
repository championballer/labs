#include <bits/stdc++.h>
using namespace std;


int inverse(int N)
{
	int r1=26,r2=N;
	int t1=0,t2=1;
	while(r2>0)
	{
		int q=r1/r2;
		int r=r1-q*r2;
		r1=r2;
		r2=r;
		int t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	return t1;
}
int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		string input,output,key;
		cout<<"Message: ";
		cin>>input;
		cin>>key;

		
		///ENCRYPTION
		cout<<"Encrypted Data: ";
		int plain[input.size()];
		for(int i=0;i<input.size();i++)
			plain[i]=input[i]-'a';
		int keyarr[input.size()];
		for(int i=0;i<input.size();i++)
			keyarr[i]=key[i%key.size()]-'a';

		int cipher[input.size()];
		for(int i=0;i<input.size();i++)
			cipher[i]=(plain[i]+keyarr[i])%26;

		for(int i=0;i<input.size();i++)
			output+=cipher[i]+'a';

		cout<<output<<endl;

		///DECRYPTION
		cout<<"Descrypted Data: ";
		input.clear();
		for(int i=0;i<output.size();i++)
			cipher[i]=output[i]-'a';
		for(int i=0;i<output.size();i++)
			keyarr[i]=key[i%key.size()]-'a';
		for(int i=0;i<output.size();i++)
			plain[i]=(cipher[i]-keyarr[i]+26)%26;
		for(int i=0;i<output.size();i++)
			input+=plain[i]+'a';

		cout<<input<<endl;
	}
}