#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lcs(string s1, string s2){

    vector<vector<int> > dp;
  	for(int i=0;i<=s1.length();i++)
    {
      vector<int> small(s2.length()+1);
      dp.push_back(small);
    }
  	dp[0][0] = 0;
  	for(int i=1;i<=s2.length();i++)
    {
      	dp[0][i] = 0;
    }
  
  	for(int j=1;j<=s1.length();j++)
    {
      	dp[j][0] = 0;
    }
  
  	for(int i=1;i<=s1.length();i++)
    {
      for(int j=1;j<=s2.length();j++)
      {
        if(s1[s1.length()-i]==s2[s2.length()-j])
        {
          dp[i][j] = dp[i-1][j-1]+1;
        }
        
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  
  	return dp[s1.length()][s2.length()];
}

int main()
{
  string s1,s2;

  cout<<"Please enter strings to compare:";
  cin>>s1>>s2;

  cout<<lcs(s1,s2)<<endl;
}
