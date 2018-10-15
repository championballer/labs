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
		cout<<i<<"->\t";
		set<pair<int,int> > S;
		for(int j=0;j<answer[i].size();j++)
			S.insert(answer[i][j]);
		for(auto it=S.begin();it!=S.end();it++)
			cout<<it->first<<","<<it->second<<"  ";
		cout<<endl;
	}
}

void distance_vector(routing_table *arr,int N,int source)
{
	for(int i=1;i<=N;i++)
	{
		int neighbour=i;
		int neighbour_distance=arr[source].distance[i];
		if(neighbour_distance==1000000 || i==source)
			continue;
		bool flag=false;
		for(int j=1;j<=N;j++)
			if(j!=source && j!=i && arr[neighbour].distance[j]>neighbour_distance+arr[source].distance[j])
			{
				flag=1;
				bool direct=false;
				if(*arr[i].path[source].begin()==0)
					direct=true;
				if(!direct)
					continue;
				arr[neighbour].path[j].clear();
				arr[neighbour].path[j].insert(source);
				arr[neighbour].distance[j]=neighbour_distance+arr[source].distance[j];
			}
			else if(j!=source && j!=i && arr[neighbour].distance[j]==neighbour_distance+arr[source].distance[j])
			{
				bool direct=false;
				if(*arr[i].path[source].begin()==0)
					direct=true;
				if(!direct)
					continue;
				arr[neighbour].path[j].insert(source);
			}
		if(flag)
			distance_vector(arr,N,neighbour);
	}
}

void helper(routing_table *arr,int source,int destination,vector<int> output)
{
	if(source==0)
	{
		output.push_back(destination);
		for(int i=0;i<output.size();i++)
			cout<<output[i]<<" ";
		cout<<endl;
		return;
	}
	output.push_back(source);
	set<int> v=arr[source].path[destination];
	for(auto it=v.begin();it!=v.end();it++)
		helper(arr,*it,destination,output);
}

void distance_vector_routing()
{
	int N;
	cout<<"Enter number of Nodes: ";
	cin>>N;
	routing_table *arr=new routing_table[N+1];
	cout<<"Enter adjacency list of nodes 1-N: "<<endl;
	for(int i=1;i<=N;i++)
	{
		arr[i].input();
		arr[i].distance[i]=0;
	}

	for(int source=1;source<=N;source++)
		distance_vector(arr,N,source);

	int source,destination;
	cout<<"Enter source and destination: ";
	cin>>source>>destination;

	int distance=arr[source].distance[destination];
	cout<<"DISTANCE: "<<distance<<endl;

	vector<int> output;
	helper(arr,source,destination,output);
}

void BFS(vector<pair<int,int> > *arr,int N,int node,int destination,int hop_count)
{
	queue<pair<int,int> > Q;
	Q.push({node,0});
	int parent[N+1],distance[N+1];
	bool mark[N+1]={0};
	mark[node]=1;
	parent[node]=-1;
	distance[node]=0;
	bool flag=false;
	int level=0;
	while(!Q.empty())
	{
		if(level==hop_count)
			break;
		int k=Q.size();
		while(k--)
		{
			pair<int,int> temp=Q.front();
			Q.pop();

			if(temp.first==destination)
			{
				flag=true;
				break;
			}
			int node=temp.first;
			for(int i=0;i<arr[node].size();i++)
				if(!mark[arr[node][i].first])
				{
					Q.push(arr[node][i]);
					distance[arr[node][i].first]=distance[node]+arr[node][i].second;
					parent[arr[node][i].first]=node;
					mark[arr[node][i].first]=1;
				}
		}
		level++;
		if(flag)
			break;
	}
	if(!flag)
	{
		cout<<"No way"<<endl;
		return;
	}
	cout<<"Distance: "<<distance[destination]<<endl;
	cout<<"PATH: "<<endl;
	int x=destination;
	while(x!=-1)
	{
		cout<<x<<" ";
		x=parent[x];
	}
	cout<<endl;
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

void flooding()
{
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

	int source,destination;
	cout<<"Enter Source and destination: ";
	cin>>source>>destination;
	int hop_count;
	cout<<"Hop Count: ";
	cin>>hop_count;
	BFS(arr,N,source,destination,hop_count);
}

void selective_flooding()
{
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

	int source,destination;
	cout<<"Enter Source and destination: ";
	cin>>source>>destination;
	int hop_count;
	cout<<"Hop Count: ";
	cin>>hop_count;
	bool *mark=new bool [N+1];
	int dist=DFS(arr,mark,source,destination,hop_count);
	if(dist==1000000)
		cout<<endl<<"No PATH"<<endl;
	else
		cout<<endl<<"Distance: "<<dist<<endl;
}

int main()
{
	link_state_routing();
	//distance_vector_routing();
	//sink_tree_routing();
	//flooding();
	//selective_flooding();
}
