#include<bits/stdc++.h>

using namespace std;

class LSP
{
public:
	vector<pair<int,int> > arr;
	int id;
	int sequence;
	int age;
};

class routing_table
{
public: 
	int distance[100];
	set<int> path[100];
	routing_table()
	{
		for(int i=0;i<100;i++)
		{
			path[i].insert(0);
			distance[i]=1000000;
		}
	}
	void input()
	{
		while(1)
		{
			int node,weight;
			cin>>node;
			if(node==-1)
				break;
			cin>>weight;
			distance[node]=weight;
		}
	}
};

void djkshtra(vector<pair<int,int> > *arr,int source,vector<pair<int,int> > *answer,int N)
{
	int distance[N+1];
	for(int i=1;i<=N;i++)
		distance[i]=1000000;
	distance[source]=0;

	set<pair<int,int> > S;
	S.insert({0,source});
	pair<int,int> parent[N+1];
	parent[source]={0,0};
	for(int i=0;i<N-1;i++)
	{
		auto it=S.begin();
		int node=it->second;
		for(int j=0;j<arr[node].size();j++)
		{
			int dest=arr[node][j].first,weight=arr[node][j].second;
			if(distance[dest]>distance[node]+weight)
			{
				auto it=S.find({distance[dest],dest});
				if(it!=S.end())
					S.erase(it);
				parent[dest]={node,weight};
				distance[dest]=distance[node]+weight;
				S.insert({distance[dest],dest});
			}
		}
		S.erase(it);
	}

	for(int dest=1;dest<=N;dest++)
	{
		int x=dest;
		while(x!=source)
		{
			answer[parent[x].first].push_back({x,parent[x].second});
			x=parent[x].first;
		}
	}
}

void sink_tree_routing()
{
	///call djkshtra with available adjacency list and source node
	int N,M;
	cout<<"Enter number of Nodes, Edges: ";
	cin>>N>>M;
	cout<<"Enter adjacency list: "<<endl;
	vector<pair<int,int> > *arr=new vector<pair<int,int> > [N+1];
	for(int i=0;i<M;i++)
	{
		int x,y,weight;
		cin>>x>>y>>weight;
		arr[x].push_back({y,weight});
		arr[y].push_back({x,weight});
	}

	int source;
	cout<<"Enter Source: ";
	cin>>source;
	vector<pair<int,int> > *answer=new vector<pair<int,int> > [N+1];
	djkshtra(arr,source,answer,N);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<answer[i].size();j++)
		{
			cout<<answer[i][j].first<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=N;i++)
	{
		cout<<i<<"->\t";
		set<pair<int,int> > S;
		for(int j=0;j<answer[i].size();j++)
			S.insert(answer[i][j]);
		for(auto it=S.begin();it!=S.end();it++)
			cout<<it->first<<","<<it->second<<"  ";
		cout<<endl;
	}


}

int main()
{
	sink_tree_routing();
	
}
