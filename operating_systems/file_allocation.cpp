#include <bits/stdc++.h>
using namespace std;

void continous_allocation()
{
	int N;
	cout<<"Number of Files: ";
	cin>>N;
	int size[N];
	cout<<"Blocks required for each file: "<<endl;
	for(int i=0;i<N;i++)
		cin>>size[i];
	int K;
	cout<<"Disk Size: ";
	cin>>K;
	bool mark[K]={0};//mark is taken as a virtual disk space sorta.
	for(int i=0;i<N;i++)
	{
		bool allocate=false;
		while(!allocate)
		{
			int rand_block=random()%K;
			bool temp=false;
			for(int j=rand_block;j<rand_block+size[i];j++)
				if(mark[j])
				{
					temp=true;
					break;
				}
			if(!temp)
			{
				cout<<i<<" "<<rand_block<<endl;
				for(int j=rand_block;j<rand_block+size[i];j++)
					mark[j]=1;
				allocate=true;
			}
		}
	}
}

class node
{
public:
	node *next;
	int data;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};

void linked_allocation()
{
	int N;
	cout<<"Number of Files: ";
	cin>>N;
	int size[N];
	cout<<"Blocks required for each file: "<<endl;
	for(int i=0;i<N;i++)
		cin>>size[i];
	int K;
	cout<<"Disk Size: ";
	cin>>K;
	bool mark[K]={0};
	pair<node*,node*> dir[N];//pair type array, each node has next pointer and we store start and end for our convenience and add accordingly
	for(int i=0;i<N;i++)
	{
		node *start=NULL,*end;
		for(int j=0;j<size[i];j++)
		{
			int rand_block=random()%K;
			while(mark[rand_block])
				rand_block=random()%K;
			node *newnode=new node(rand_block);
			mark[rand_block]=1;
			if(start==NULL)
				start=end=newnode;
			else
			{
				end->next=newnode;
				end=newnode;
			}
		}
		dir[i]={start,end};
	}
	for(int i=0;i<N;i++)
	{
		cout<<i<<" - ";
		node *start=dir[i].first;
		while(start!=NULL)
		{
			cout<<start->data<<" ";
			start=start->next;
		}
		cout<<endl;
	}
}

void indexed_allocation()
{
	int N;
	cout<<"Number of Files: ";
	cin>>N;
	int size[N];
	cout<<"Blocks required for each file: "<<endl;
	for(int i=0;i<N;i++)
		cin>>size[i];
	int K;
	cout<<"Disk Size: ";
	cin>>K;
	bool mark[K]={0};

	map<int,vector<int> > M;
	int dir[N];
	for(int i=0;i<N;i++)
	{
		int index_block=random()%K;
		while(mark[index_block])//already allocated
			index_block=random()%K;
		dir[i]=index_block;//index block for the file
		mark[index_block]=1;//marked for allocation
		vector<int> temp;
		for(int j=0;j<size[i];j++)
		{
			int rand_block=random()%K;
			while(mark[rand_block])
				rand_block=random()%K;
			mark[rand_block]=1;
			temp.push_back(rand_block);
		}
		M.insert({index_block,temp});//insert file numbers vector for the index
	}

	for(int i=0;i<N;i++)
	{
		cout<<i<<" "<<dir[i]<<" - ";
		auto it=M.find(dir[i]);
		vector<int> x=it->second;
		for(int i=0;i<x.size();i++)
			cout<<x[i]<<" ";
		cout<<endl;
	}
}

int main()
{
	//continous_allocation();
	//linked_allocation();
	//indexed_allocation();
}
