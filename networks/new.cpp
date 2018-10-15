#include <bits/stdc++.h>
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

void update_graph(vector<pair<int,int> > *arr,int node,int weight=0)
{
	for(int i=0;i<arr[node].size();i++)
	{
		arr[node][i].second+=weight;
		update_graph(arr,arr[node][i].first,arr[node][i].second);
	}
}

int DFS(vector<pair<int,int> >  *arr,bool *mark,int node,int destination,int hop_count)
{
	if(mark[node] || hop_count==0)
		return 1000000;
	if(node==destination)
	{
		cout<<destination<<" ";
		return 0;
	}
	mark[node]=1;
	for(int i=0;i<arr[node].size();i++)
	{
		int distance=DFS(arr,mark,arr[node][i].first,destination,hop_count-1);
		if(distance!=1000000)
		{
			cout<<node<<" ";
			return distance+arr[node][i].second;
		}
	}
	return 1000000;
}

void link_state_routing()
{
	int N;
	cout<<"Number of nodes: ";
	cin>>N;
	LSP *obj=new LSP[N];
	cout<<"ID, sequence, age, LIST: "<<endl;
	for(int i=0;i<N;i++)
	{
		cin>>obj[i].id>>obj[i].sequence>>obj[i].age;
		int ch,weight;
		while(1)
		{
			cin>>ch;
			if(ch==-1)
				break;
			cin>>weight;
			obj[i].arr.push_back({ch,weight});
		}	
	}

	vector<pair<int,int> > *arr=new vector<pair<int,int> > [N+1];
	for(int i=0;i<N;i++)
		arr[obj[i].id]=obj[i].arr;
	
	vector<pair<int,int> > *answer=new vector<pair<int,int> > [N+1];

	int source;
	cout<<"SOURCE: "<<endl;
	cin>>source;
	djkshtra(arr,source,answer,N);

	set<pair<int,int> > S;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<answer[i].size();j++)
			S.insert(answer[i][j]);
		answer[i].clear();
		for(auto it=S.begin();it!=S.end();it++)
			answer[i].push_back(*it);
		S.clear();
	}

	update_graph(answer,source);

	for(int i=1;i<=N;i++)
	{
		cout<<i<<"->\t";
		for(int j=0;j<answer[i].size();j++)
			cout<<answer[i][j].first<<","<<answer[i][j].second<<" ";
		cout<<endl;
	}

	bool *mark=new bool [N+1];
	cout<<DFS(arr,mark,1,5,3);
	
}

int main()
{

	link_state_routing();
}
