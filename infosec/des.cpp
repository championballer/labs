#include <bits/stdc++.h>
using namespace std;

void initial_permutation(string &input)
{
	string temp;
	int p[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
	for(int i=0;i<64;i++)
		temp+=input[p[i]-1];
	input=temp;
}
void final_permutation(string &input)
{
	int p[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
	int invp[64];
	for(int i=0;i<64;i++)
		invp[p[i]-1]=i+1;

	string temp;
	for(int i=0;i<64;i++)
		temp+=input[invp[i]-1];
	input=temp;
}
string key_generation(string cipher,int *numberofshift,int round)
{
	///SHIFT
	for(int i=0;i<numberofshift[round];i++)
	{
		char temp=cipher[0];
		for(int j=0;j<27;j++)
			cipher[j]=cipher[j+1];
		cipher[27]=temp;

		temp=cipher[28];
		for(int j=28;j<55;j++)
			cipher[j]=cipher[j+1];
		cipher[55]=temp;
	}

	///COMPRESSION P-BOX
	int p[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
	string x;
	for(int i=0;i<48;i++)
		x+=cipher[p[i]-1];
	return x;
}
string DESfunc(string k,string s)
{
	///EXPANSION
	string temp;
	for(int i=0;i<32;)
	{
		temp+=s[(i-1+32)%32];
		for(int j=0;j<4;j++,i++)
			temp+=s[i];
		temp+=s[i%32];
	}

	///KEY MIXER/WHITENER
	for(int i=0;i<32;i++)
		if(temp[i]==k[i])
			temp[i]='0';
		else
			temp[i]='1';

	///COMPRESSION S-BOX(Assuming S1=S2...=S8)
	int sbox[4][16]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,10,3,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13};
	string final;
	for(int i=0;i<48;i+=6)
	{
		string x;
		for(int j=i;j<i+6;j++)
			x+=temp[j];
		int row=(x[5]-'0')*2+x[0]-'0';
		int col=(x[4]-'0')*8+(x[3]-'0')*4+(x[2]-'0')*2+(x[1]-'0');
		int num=sbox[row][col];
		x.clear();
		for(int j=0;j<4;j++,num/=2)
			x+=num%2+'0';
		for(int j=3;j>=0;j--)
			final+=x[j];
	}

	///STRAIGHT P-BOX
	int p[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
	temp.clear();
	for(int i=0;i<32;i++)
		temp+=final[p[i]-1];
	return temp;
}
int main()
{
	///ENCRYPTION
	int numberofshift[16];
	for(int i=0;i<16;i++)
		if(i==0 || i==1 || i==8 || i==15)
			numberofshift[i]=1;
		else
			numberofshift[i]=2;
	for(int i=1;i<16;i++)
		numberofshift[i]+=numberofshift[i-1];

	cout<<endl<<"ENCRYPTION: "<<endl<<endl;
	string input,cipherkey;
	cout<<"Enter Input String(64 bits): ";
	cin>>input;
	cout<<"Enter Cipher Key(56 bits): ";
	cin>>cipherkey;
	cout<<"INPUT: "<<input<<endl;
	initial_permutation(input);
	cout<<"INITIAL PERMUTATION: "<<input<<endl;

	for(int i=0;i<16;i++)
	{
		string key=key_generation(cipherkey,numberofshift,i);
		string L,R;
		for(int i=0;i<32;i++)
			L+=input[i];
		for(int i=32;i<64;i++)
			R+=input[i];

		string temp=DESfunc(key,R);

		for(int i=0;i<32;i++)
			if(temp[i]==L[i])
				L[i]='0';
			else
				L[i]='1';
		
		if(i!=15)
			swap(L,R);
		for(int i=0;i<32;i++)
			input[i]=L[i];
		for(int i=32;i<64;i++)
			input[i]=R[i-32];

		cout<<"After Round #"<<i+1<<": "<<input<<endl;
	}
	final_permutation(input);
	cout<<"FINAL PERMUTATION: "<<input<<endl;


	///DECRYPTION
	cout<<endl<<"DECRYPTION: "<<endl<<endl;
	initial_permutation(input);
	cout<<"INITIAL PERMUTATION: "<<input<<endl;
	for(int i=0;i<16;i++)
	{
		string key=key_generation(cipherkey,numberofshift,15-i);
		string L,R;
		for(int i=0;i<32;i++)
			L+=input[i];
		for(int i=32;i<64;i++)
			R+=input[i];
		
		if(i!=0)
			swap(L,R);
		
		string temp=DESfunc(key,R);

		for(int i=0;i<32;i++)
			if(temp[i]==L[i])
				L[i]='0';
			else
				L[i]='1';
		
		for(int i=0;i<32;i++)
			input[i]=L[i];
		for(int i=32;i<64;i++)
			input[i]=R[i-32];

		cout<<"After Round #"<<i+1<<": "<<input<<endl;
	}
	final_permutation(input);
	cout<<"FINAL PERMUTATION: "<<input<<endl;
}