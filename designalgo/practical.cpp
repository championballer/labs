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
  while(outer<n)
  {
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

/*
input : 

6 9
1 2 1
1 3 9
1 6 14
2 3 10
3 6 2
6 5 9
5 4 6
3 4 11
2 4 15

*/

int main()
{
  int n,e;
  cout<<"Please enter the number of nodes and edges:";
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
  cout<<"Please enter source, destination and corresponding weights for each edge:";
  for(int i=0;i<e;i++)
  {
    int src,des,weight;
    cin>>src>>des>>weight;
    edges[src-1][des-1]=weight;
    edges[des-1][src-1]=weight;
  }
  
  bool* visited=new bool[n];
  for(int i=0;i<n;i++)visited[n]=false;
   
  int source;
  cout<<"Please enter the source node:";
  cin>>source;  
  int* distance=new int[n];
  distance[source-1]=0;
  for(int i=0;i<n;i++)
  {
    if(i==source-1)continue;
    distance[i]=INT_MAX;
  }

  djikstra(edges,n,visited,distance);
  for(int i=0;i<n;i++)
  {
    cout<<i+1<<" "<<distance[i]<<endl;
  }
  return 0;
}
