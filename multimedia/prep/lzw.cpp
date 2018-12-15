#include <bits/stdc++.h>
using namespace std;

void lzw(string str)
{
	vector<int> ans;
	map<string,int> M;
	map<int,string> decodeM;
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string temp;
		cin>>temp;
		M[temp]=M.size()+1;
		decodeM[i+1]=temp;
	}
	int i=0;
	while(i<str.size())
	{
		string temp;
		int pos=0;
		bool flag=false;
		while(i<str.size())
		{
			temp+=str[i];
			auto it=M.find(temp);
			i++;
			if(it==M.end())
			{
				flag=true;
				M[temp]=M.size()+1;
				break;
			}
			pos=it->second;
		
		}
		ans.push_back(pos);
		if(i!=str.size())
			i--;
		else if(flag)
		{
			string temp;
			temp+=str[i-1];
			ans.push_back(M[temp]);
		}
	}

	auto it=M.begin();
	while(it!=M.end())
	{
	 	cout<<it->first<<" "<<it->second<<endl;
	 	it++;
	}

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	///DECODE
	int old=ans[0];
	string decode;
	decode+=decodeM[old];
	i=1;
	char C;
	while(i<ans.size())
	{
		int newchar=ans[i];
		auto it=decodeM.find(newchar);
		string S;
		if(it!=decodeM.end())
			S=it->second;
		else
		{
			S=decodeM[old];
			S+=C;
		}
		decode+=S;
		C=S[0];
		decodeM[decodeM.size()+1]=decodeM[old]+C;
		old=newchar;
		i++;
	}
	cout<<decode<<endl;
}
int main()
{
	string str;
	cin>>str;
	lzw(str);
}