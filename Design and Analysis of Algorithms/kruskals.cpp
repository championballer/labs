#include<bits/stdc++.h>

using namespace std;

class edge{
	public:
  	int source;
  	int destination;
  	int weight;
};

bool compare(edge e1,edge e2)
{
  return e1.weight<e2.weight;
}

int findParent(int* parent,int i)
{
  if(parent[i]==i)
  {
    return i;
  }
  
  else return findParent(parent,parent[i]);
}
int main()
{
  int n,e;
  cout<<"Please enter the number of nodes and edges:";
  cin>>n>>e;
  
  edge* input=new edge[e];
  cout<<"Please enter source, destination and corresponding weights for each edge:";
  for(int i=0;i<e;i++)
  {

    int src, des, w;
    cin>>src>>des>>w;
    input[i].source=src;
    input[i].destination=des;
    input[i].weight=w;
  }
  
  sort(input,input+e,compare);
  edge* output=new edge[n-1];
  int* parent=new int[n];
  for(int i=0;i<n;i++)
  {
    parent[i]=i;
  }
  
  int count=0,current=0;
  while(count<n-1)
  {
    
    int sourceParent=findParent(parent,input[current].source);
    int destinationParent=findParent(parent,input[current].destination);
    
    if(sourceParent==destinationParent)
    {
      current++;
      continue;
    }
    
    else{
      output[count]=input[current];
      parent[findParent(parent,input[current].source)]=parent[findParent(parent,input[current].destination)];
      count++;
      current++;
    }
  }
  
  for(int i=0;i<n-1;i++)
  {
    if(output[i].destination<output[i].source)
    {
      cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
    
    else cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
  }
  
  
}