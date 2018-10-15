#include <bits/stdc++.h>
using namespace std;

class process
{
public:
	int burst_time;
	int arrival_time;
	int priority;
	int i;//process number
	void input(int p)//constructor taking input all values and passing process number along
	{
		cout<<"Please enter the burst time for process "<<p<<":";
		cin>>burst_time;
		cout<<"Please enter the arrival time for process "<<p<<":";
		cin>>arrival_time;
		cout<<"Please enter the priority for process "<<p<<":";
		cin>>priority;
		i=p;
	}
};

bool mycompare1(process A,process B)
{
	if(A.arrival_time<B.arrival_time)
		return true;
	return false;
}

void FCFS(process arr[100],int N)//array of processes(max size=100), size of array to be used here
{
	sort(arr,arr+N,mycompare1);//sorting according to arrival times
	int tat[N],wt[N],current_time=0;//tat times and waiting times for each process serially
	for(int i=0;i<N;i++)
	{	
		int completion_time=max(arr[i].arrival_time,current_time)+arr[i].burst_time;
		current_time=completion_time;
		tat[arr[i].i]=completion_time-arr[i].arrival_time;
		wt[arr[i].i]=tat[arr[i].i]-arr[i].burst_time;
	}
	cout<<"TURN AROUND TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<tat[i]<<" ";
	cout<<endl<<"WAITING TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<wt[i]<<" ";
	cout<<endl;
}

void SJF(process arr[100],int N)
{
	int tat[N],wt[N],current_time=0;
	bool mark[N]={0};
	queue<int> Q;//main queue
	for(int time=0;;time++)
	{
		for(int i=0;i<N;i++)
			if(time>=arr[i].arrival_time && !mark[i])//if the process has aleady arrived and hasn't been processed yet, enqueue
			{
				Q.push(i);
				mark[i]=1;
			}
		queue<int> temp=Q;//temporary queue for calculation of min time
		int min_time=INT_MAX,p=-1;
		while(!temp.empty())
		{
			int i=temp.front();
			if(arr[i].burst_time<min_time || (arr[i].burst_time==min_time && arr[i].arrival_time<arr[p].arrival_time))
			{
				min_time=arr[i].burst_time;
				p=i;
			}
			temp.pop();
		}
		while(!Q.empty())
		{
			if(p!=Q.front())//p is the process with min burst time i.e. it is to be executed
				temp.push(Q.front());
			Q.pop();
		}
		Q=temp;
		bool con=false;
		if(p!=-1)
		{
			time+=arr[p].burst_time-1;
			tat[p]=time-arr[p].arrival_time+1;
			wt[p]=tat[p]-arr[p].burst_time;
		}
		for(int i=0;i<N;i++)
			if(!mark[i])
				con=true;
		if(!con && Q.empty())
			break;

	}
	cout<<"TURN AROUND TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<tat[i]<<" ";
	cout<<endl<<"WAITING TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<wt[i]<<" ";
	cout<<endl;
}

void SRTF(process arr[100],int N)
{
	int tat[N],wt[N],current_time=0;
	bool mark[N]={0};
	int original_burst_time[N];
	for(int i=0;i<N;i++)
		original_burst_time[i]=arr[i].burst_time;

	queue<int> Q;
	for(int time=0;;time++)
	{
		for(int i=0;i<N;i++)
			if(time>=arr[i].arrival_time && !mark[i])
			{
				Q.push(i);
				mark[i]=1;
			}
		queue<int> temp=Q;
		int min_time=INT_MAX,p=-1;
		while(!temp.empty())
		{
			int i=temp.front();
			if(arr[i].burst_time<min_time || (arr[i].burst_time==min_time && arr[i].arrival_time<arr[p].arrival_time))
			{
				min_time=arr[i].burst_time;
				p=i;
			}
			temp.pop();
		}
		if(p!=-1)
		{
			arr[p].burst_time--;
			if(arr[p].burst_time==0)
			{
				while(!Q.empty())
				{
					if(p!=Q.front())
						temp.push(Q.front());
					Q.pop();
				}
				Q=temp;
				tat[p]=time-arr[p].arrival_time+1;
				wt[p]=tat[p]-original_burst_time[p];
			}
		}
		bool con=false;
		for(int i=0;i<N;i++)
			if(!mark[i])
				con=true;
		if(!con && Q.empty())
			break;
	}
	cout<<"TURN AROUND TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<tat[i]<<" ";
	cout<<endl<<"WAITING TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<wt[i]<<" ";
	cout<<endl;
}

void priority_non(process arr[100],int N)
{
	int tat[N],wt[N],current_time=0;
	bool mark[N]={0};
	queue<int> Q;
	for(int time=0;;time++)
	{
		for(int i=0;i<N;i++)
			if(time>=arr[i].arrival_time && !mark[i])
			{
				Q.push(i);
				mark[i]=1;
			}
		queue<int> temp=Q;
		int min_time=INT_MAX,p=-1;
		while(!temp.empty())
		{
			int i=temp.front();
			if(arr[i].priority<min_time || (arr[i].priority==min_time && arr[i].arrival_time<arr[p].arrival_time))
			{
				min_time=arr[i].priority;
				p=i;
			}
			temp.pop();
		}
		while(!Q.empty())
		{
			if(p!=Q.front())
				temp.push(Q.front());
			Q.pop();
		}
		Q=temp;
		bool con=false;
		if(p!=-1)
		{
			time+=arr[p].burst_time-1;
			tat[p]=time-arr[p].arrival_time+1;
			wt[p]=tat[p]-arr[p].burst_time;
		}
		for(int i=0;i<N;i++)
			if(!mark[i])
				con=true;
		if(!con && Q.empty())
			break;
	}
	cout<<"TURN AROUND TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<tat[i]<<" ";
	cout<<endl<<"WAITING TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<wt[i]<<" ";
	cout<<endl;
}

void priority_pre(process arr[100],int N)
{
	int tat[N],wt[N],current_time=0;
	bool mark[N]={0};
	int original_burst_time[N];
	for(int i=0;i<N;i++)
		original_burst_time[i]=arr[i].burst_time;

	queue<int> Q;
	for(int time=0;;time++)
	{
		for(int i=0;i<N;i++)
			if(time>=arr[i].arrival_time && !mark[i])
			{
				Q.push(i);
				mark[i]=1;
			}
		queue<int> temp=Q;
		int min_time=INT_MAX,p=-1;
		while(!temp.empty())
		{
			int i=temp.front();
			if(arr[i].priority<min_time || (arr[i].priority==min_time && arr[i].arrival_time<arr[p].arrival_time))
			{
				min_time=arr[i].priority;
				p=i;
			}
			temp.pop();
		}
		if(p!=-1)
		{
			arr[p].burst_time--;
			if(arr[p].burst_time==0)
			{
				while(!Q.empty())
				{
					if(p!=Q.front())
						temp.push(Q.front());
					Q.pop();
				}
				Q=temp;
				tat[p]=time-arr[p].arrival_time+1;
				wt[p]=tat[p]-original_burst_time[p];
			}
		}
		bool con=false;
		for(int i=0;i<N;i++)
			if(!mark[i])
				con=true;
		if(!con && Q.empty())
			break;
	}
	cout<<"TURN AROUND TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<tat[i]<<" ";
	cout<<endl<<"WAITING TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<wt[i]<<" ";
	cout<<endl;
}

void Round_Robbin(process arr[100],int N,int time_slice)
{
	int tat[N],wt[N],current_time=0;
	bool mark[N]={0};
	int original_burst_time[N];
	int work[N]={0};
	for(int i=0;i<N;i++)
		original_burst_time[i]=arr[i].burst_time;

	queue<int> Q;
	for(int time=0;;time++)
	{
		for(int i=0;i<N;i++)
			if(time>=arr[i].arrival_time && !mark[i])
			{
				Q.push(i);
				mark[i]=1;
			}
		if(!Q.empty())
		{
			int p=Q.front();
			arr[p].burst_time--;
			work[p]++;
			if(work[p]%time_slice==0)
			{
				if(arr[p].burst_time==0)
				{
					Q.pop();
					tat[p]=time-arr[p].arrival_time+1;
					wt[p]=tat[p]-original_burst_time[p];
				}
				else
				{
					Q.pop();
					Q.push(p);
				}
			}
			else if(arr[p].burst_time==0)
			{
				Q.pop();
				tat[p]=time-arr[p].arrival_time+1;
				wt[p]=tat[p]-original_burst_time[p];
			}
		}
		bool con=false;
		for(int i=0;i<N;i++)
			if(!mark[i])
				con=true;
		if(!con && Q.empty())
			break;
	}
	cout<<"TURN AROUND TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<tat[i]<<" ";
	cout<<endl<<"WAITING TIME: "<<endl;
	for(int i=0;i<N;i++)
		cout<<wt[i]<<" ";
	cout<<endl;
}

int main()
{
	int N;
	cout<<"Number of processes: ";
	cin>>N;
	process arr[100];
	cout<<"INPUT: "<<endl;
	for(int i=0;i<N;i++)
		arr[i].input(i);

	FCFS(arr,N);
	//SJF(arr,N);
	//SRTF(arr,N);
	//priority_non(arr,N);
	//priority_pre(arr,N);
	/*cout<<"Time Slice: ";
	int time_slice;
	cin>>time_slice;
	Round_Robbin(arr,N,time_slice);
	*/
}
