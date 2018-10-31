#include <bits/stdc++.h>
using namespace std;

class edge{
  public:
  int source;
  int destination;
  int weight;
};

int leastWeight(int* weight,bool* visited,int n)
{
  int i=0;
  int min=INT_MAX;
  int index=-1;
  while(i<n)
  {
    if(weight[i]<min && !visited[i])
    {
      min=weight[i];
      index=i;
    }
    i++;
  }
  
  return index;
}

void PrimAlgo(int** edges, int n, bool* visited,int* parent,int* weightArr)
{
  int outer=0;
  while(outer<n)
  {
   	int nextVertex=leastWeight(weightArr,visited,n);
    if(nextVertex==-1)
    {
      return;
    }
  	visited[nextVertex]=true;
  
  	for(int i=0;i<n;i++)
  	{
    	if(i==nextVertex)
    	{
      	continue;
    	}
    
   		 if(!visited[i] && edges[nextVertex][i]!=0)
    	 {
      		if(weightArr[i]>edges[nextVertex][i])
      		{
        	parent[i]=nextVertex;
      		weightArr[i]=edges[nextVertex][i];
      		}
         }
  	}
    outer++;
  }
}

edge* makeMST(int* parent, int* weight, int n)
{
  edge* output=new edge[n-1];
  for(int i=1;i<n;i++)
  {
    output[i-1].source=parent[i];
    output[i-1].destination=i;
    output[i-1].weight=weight[i];
  }
  
  return output;
}

int main()
{
  
  //taking Input;
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
    int src, des, weight;
    cin>>src>>des>>weight;
    edges[src][des]=weight;
    edges[des][src]=weight;
  }
  
    
  bool* visited=new bool[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=false;
  }
  
  int* parent=new int[n];
  parent[0]=-1;
  int* weightArr=new int[n];
  weightArr[0]=0;
  for(int i=1;i<n;i++)
  {
    weightArr[i]=INT_MAX;
  }
	
  PrimAlgo(edges,n,visited,parent,weightArr);
  
  
  edge* output=makeMST(parent,weightArr,n);
  for(int i=0;i<n-1;i++)
  {
    if(output[i].source<output[i].destination)
    {
      cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    }
    
    else cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
  }
 
  return 0;
}
