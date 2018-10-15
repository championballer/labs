#include <bits/stdc++.h>
using namespace std;

void bankers()
{
	int N,M;
	cout<<"Number of Processes, Number of Resources: ";
	cin>>N>>M;
	int allocation[N][M],maximum[N][M],available[M],need[N][M],work[M];
	cout<<"Allocation: "<<endl;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>allocation[i][j];
	cout<<"Maximum: "<<endl;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cin>>maximum[i][j];
			need[i][j]=maximum[i][j]-allocation[i][j];
		}
	cout<<"Available: ";
	for(int i=0;i<M;i++)
	{
		cin>>available[i];
		work[i]=available[i];
	}

	bool finish[N]={0};
	vector<int> safe_seq;
	for(int i=0;i<N;i++)
		for(int i=0;i<N;i++)
		{
			if(finish[i])
				continue;
			bool flag=true;
			for(int j=0;j<M;j++)
				if(need[i][j]>work[j])
				{
					flag=false;
					break;
				}
			if(flag)
			{
				for(int j=0;j<M;j++)
					work[j]+=allocation[i][j];
				safe_seq.push_back(i);
				finish[i]=true;
			}
		}
	bool deadlock=false;
	for(int i=0;i<N;i++)
		if(!finish[i])
		{
			cout<<i<<" ";
			deadlock=true;
		}
	if(deadlock)
		cout<<"DEADLOCK"<<endl;
	else
	{
		for(int i=0;i<safe_seq.size();i++)
			cout<<safe_seq[i]<<" ";
		cout<<endl;
	}
}

void request()
{
	int N,M;
	cout<<"Number of Processes, Number of Resources: ";
	cin>>N>>M;
	int allocation[N][M],maximum[N][M],available[M],need[N][M],work[M];
	cout<<"Allocation: "<<endl;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>allocation[i][j];
	cout<<"Maximum: "<<endl;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cin>>maximum[i][j];
			need[i][j]=maximum[i][j]-allocation[i][j];
		}
	cout<<"Available: ";
	for(int i=0;i<M;i++)
	{
		cin>>available[i];
		work[i]=available[i];
	}

	int request_process,req[M];
	cout<<"Request: ";
	cin>>request_process;
	for(int i=0;i<M;i++)
		cin>>req[i];

	bool valid=true;
	for(int i=0;i<M;i++)
		if(req[i]>need[request_process][i])
			valid=false;
	if(!valid)
	{
		cout<<"INVALID REQUEST"<<endl;
		return;
	}

	bool grant=true;
	for(int i=0;i<M;i++)
		if(req[i]>work[i])
			grant=false;
	if(!grant)
	{
		cout<<"WAIT"<<endl;
		return;
	}

	for(int i=0;i<M;i++)
	{
		need[request_process][i]-=req[i];
		allocation[request_process][i]+=req[i];
		available[i]-=req[i];
		work[i]-=req[i];
	}

	bool finish[N]={0};
	vector<int> safe_seq;
	for(int i=0;i<N;i++)
		for(int i=0;i<N;i++)
		{
			if(finish[i])
				continue;
			bool flag=true;
			for(int j=0;j<M;j++)
				if(need[i][j]>work[j])
				{
					flag=false;
					break;
				}
			if(flag)
			{
				for(int j=0;j<M;j++)
					work[j]+=allocation[i][j];
				safe_seq.push_back(i);
				finish[i]=true;
			}
		}
	bool deadlock=false;
	for(int i=0;i<N;i++)
		if(!finish[i])
		{
			cout<<i<<" ";
			deadlock=true;
		}
	if(deadlock)
		cout<<"DEADLOCK"<<endl;
	else
	{
		for(int i=0;i<safe_seq.size();i++)
			cout<<safe_seq[i]<<" ";
		cout<<endl;
	}
}

void detection()
{
	int N,M;
	cout<<"Number of Processes, Number of Resources: ";
	cin>>N>>M;
	int allocation[N][M],request[N][M],available[M],work[M];
	cout<<"Allocation: "<<endl;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>allocation[i][j];
	cout<<"Request: "<<endl;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>request[i][j];
	cout<<"Available: ";
	for(int i=0;i<M;i++)
	{
		cin>>available[i];
		work[i]=available[i];
	}

	bool finish[N];
	for(int i=0;i<N;i++)
	{
		bool flag=true;
		for(int j=0;j<M;j++)
			if(allocation[i][j]!=0)
				flag=false;
		finish[i]=flag;
	}

	vector<int> safe_seq;
	for(int i=0;i<N;i++)
		for(int i=0;i<N;i++)
		{
			if(finish[i])
				continue;
			bool flag=true;
			for(int j=0;j<M;j++)
				if(request[i][j]>work[j])
				{
					flag=false;
					break;
				}
			if(flag)
			{
				for(int j=0;j<M;j++)
					work[j]+=allocation[i][j];
				safe_seq.push_back(i);
				finish[i]=true;
			}
		}
	bool deadlock=false;
	for(int i=0;i<N;i++)
		if(!finish[i])
		{
			cout<<i<<" ";
			deadlock=true;
		}
	if(deadlock)
		cout<<"DEADLOCK"<<endl;
	else
	{
		for(int i=0;i<safe_seq.size();i++)
			cout<<safe_seq[i]<<" ";
		cout<<endl;
	}
}

int main()
{
	bankers();
	//request();
	//detection();
}
