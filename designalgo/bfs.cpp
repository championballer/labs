#include<iostream>
#include<queue>

using namespace std;

void print(int** edges, int n, int sv, bool* visited)
{
  queue<int> pendingVertices;
  pendingVertices.push(sv);
  visited[sv]=true;
  while(pendingVertices.size()!=0)
  {
    int p=pendingVertices.front();
    cout<<p<<" ";
    pendingVertices.pop();
    for(int i=0;i<n;i++)
      if(edges[p][i]==1 && !visited[i])
      {
        pendingVertices.push(i);
        visited[i]=true;
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
    edges[f][t]=1;
    edges[t][f]=1;
  }
  
  bool* visited=new bool[n];
  for(int i =0;i<n;i++)
  {
    visited[i]=false;
  }
  
  print(edges, n, 0, visited);
}