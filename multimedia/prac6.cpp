#include <bits/stdc++.h>

using namespace std;

vector<int> encryption()
{
 	string s;
	cin>>s;
	int N;
 	map<string ,int>mapp;
	map<int,string> decodeM;
	cout<<"Number of Distinct characters: ";
	cin>>N;
	while(N--)
	{
	string ch;
	cin>>ch;
	mapp.insert({ch,mapp.size()+1});
	decodeM[i+1]=temp;
	}

	int index;
	vector<int>v;
	int i=0;
	while(i<s.size())
	{
		string str="";
	 	index=0;
		for(int j=i;j<s.size();j++)
		{
	 		str+=s[j];
	 		map<string ,int>::iterator it= mapp.find(str);
	 		if(it!=mapp.end())
	 		{
	 			index=it->second;
	 			i++;
	 		}

	 		else
	 		{
	 			mapp.insert({str,mapp.size()+1});
	 			v.push_back(index);
	 			break;
	 		}
		}
	}

	v.push_back(index);
	auto it=mapp.begin();
	while(it!=mapp.end())
	{
	 	cout<<it->first<<" "<<it->second<<endl;
	 	it++;
	}

	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;

	int old=v[0];
	string decode;

	decode+=decodeM[old];
	i=1;
	char C;
	while(i<v.size())
	{
		int newchar=v[i];
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
	return v;
}

int main()
{
	encryption();
}