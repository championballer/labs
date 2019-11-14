/*
KMP String Matching Algorithm
*/

#include<bits/stdc++.h>

using namespace std;

void string_matching(string hay,string pattern,int * lps, vector<int>& pos)
{
	for(int i=0,j=0;i<hay.length();)
	{
		if(hay[i]==pattern[j])
		{
			i++;
			j++;

			if(j==pattern.length())
			{
				pos.push_back(i-j);
			}

			continue;
		}

		else
		{
			if(j>0)
			{
				j = lps[j-1];
			}

			else
			{
				i++;
				continue;
			}
		}
	}
}

void pre_process(string pattern,int * lps)
{
	lps[0] = 0;
	for(int i=0,j=1;j<pattern.length();)
	{
		if(pattern[i]==pattern[j])
		{
			i++;
			lps[j] = i;
			j++;
			continue;
		}

		else
		{
			if(i>0)
			{
				i = lps[i-1];
				continue;
			}

			else
			{
				lps[j] = i;
				j++;
				continue;
			}
		}
	}
}

int main()
{
	string hay;
	string pattern;

	getline(cin,hay);
	getline(cin,pattern);

	int * lps = new int[pattern.length()];
	pre_process(pattern,lps);


	//printing lps
	// for(int i=0;i<pattern.length();i++)
	// {
	// 	cout<<lps[i]<<" ";
	// }
	// cout<<endl;

	vector<int> pos;
	string_matching(hay,pattern,lps,pos);

	for(int i=0;i<pos.size();i++)
	{
		cout<<pos[i]<<" ";
	}
	cout<<endl;
}