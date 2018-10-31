#include <iostream>
#include<climits>
using namespace std;

int minDis(int* distance, bool* visited,int n)
{
  int i=0;
  int index=-1;
  int min=INT_MAX;
  while(i<n)
  {
    if(!visited[i] && distance[i]<min)
    {
      min=distance[i];
      index=i;
    }
    i++;
  }
  return index;
}

void djikstra(int** edges,int n,bool* visited,int* distance)
{
  int outer=0;
  while(outer<n){
    int nextVertex=minDis(distance,visited,n);
    if(nextVertex==-1)
    {
      return;
    }
    visited[nextVertex]=true;
	for(int i=0;i<n;i++)
    {
      if(i==nextVertex)continue;
      if(!visited[i] && edges[nextVertex][i]!=0)
      {
        int cdis=distance[nextVertex]+edges[nextVertex][i];
        if(cdis<distance[i])
        {
          distance[i]=cdis;
        }
      }
    }
    outer++;
  }
}

int main()
{
  int n,e;
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
  
  for(int i=0;i<e;i++)
  {
    int src,des,weight;
    cin>>src>>des>>weight;
    edges[src][des]=weight;
    edges[des][src]=weight;
  }
  
  bool* visited=new bool[n];
  for(int i=0;i<n;i++)visited[n]=false;
    
  int* distance=new int[n];
  distance[0]=0;
  for(int i=1;i<n;i++)
  {
    distance[i]=INT_MAX;
  }

  djikstra(edges,n,visited,distance);
  for(int i=0;i<n;i++)
  {
    cout<<i<<" "<<distance[i]<<endl;
  }
  return 0;
}
