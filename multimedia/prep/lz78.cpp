#include <bits/stdc++.h>
using namespace std;

void lz78()
{
	char current;
	cin>>current;
	map<string,int> M;
	vector<pair<int,char>> ans;
	while(current!='0')
	{
		string temp;
		int pos=0;
		char ch=0;
		while(current!='0')
		{
			temp+=current;
			auto it=M.find(temp);
			if(it==M.end())
			{
				ch=current;
				break;
			}
			pos=it->second;
			cin>>current;
		}
		ans.push_back({pos,ch});
		M[temp]=M.size()+1;
		cin>>current;
		
	}

	cout<<"Encoded:"<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;

	///DECODE
	
	string decode;
	M.clear();
	map<int,string> decodeM;
	for(int i=0;i<ans.size();i++)
	{
		int pos=ans[i].first;
		char ch=ans[i].second;
		string temp;
		if(pos==0)
			temp+=ch;
		else
		{
			temp+=decodeM[pos];
			temp+=ch;
		}
		decodeM[decodeM.size()+1]=temp;
		decode+=temp;
	}
	cout<<"Decoded:"<<decode<<endl;

}
int main()
{
	lz78();
}