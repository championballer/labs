#include<bits/stdc++.h>

using namespace std;

void print(int** edges, int n, int sv, bool* visited)
{
  cout<<sv+1<<endl;
  visited[sv]=true;

  for(int i=0;i<n;i++)
  {
    if(edges[sv][i]==1 && !visited[i])
    {
      print(edges,n,i,visited);
    }
  }
}

int main()
{
  int n, e;
  cin>>n>>e;
  
  int** edges=new int*[n];
  for(int i=0;i<n;i++)
  {
    edges[i]=new int[n];
    for(int j=0;j<n;j++)
    {
		edges[i][j]=0;
    }
  }
  
  for(int j=0;j<e;j++)
  {
    int f,t;
    cin>>f>>t;
    edges[f-1][t-1]=1;
    edges[t-1][f-1]=1;
  }
  
  bool* visited=new bool[n];
  for(int i =0;i<n;i++)
  {
    visited[i]=false;
  }
  
  print(edges, n, 0, visited);
}