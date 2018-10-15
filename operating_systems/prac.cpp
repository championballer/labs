#include<bits/stdc++.h>

using namespace std;

class process
{
	public:
	int seq;
	int burst_time;
	int arrival_time;
	int i;//process number
	void input(int p,int seq)//constructor taking input all values and passing process number along
	{
		cout<<"Please enter the burst time for process "<<seq<<":";
		cin>>burst_time;
		cout<<"Please enter the arrival time for process "<<seq<<":";
		cin>>arrival_time;
		this->seq=seq;
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


int main()
{
	int priority;
	process queue1[100];
	process queue2[100];
	process queue3[100];
	int n;
	cout<<"Please enter the number of processes to be scheduled:";
	cin>>n;
	int q1=0;
	int q2=0;
	int q3=0;
	for(int i=0;i<n;i++)
	{
		cout<<"Please enter the priority of process to be executed(0,1,2)(2 being highest):";
		cin>>priority;
		if(priority==0)
		{
			process p1;
			p1.input(q1,i);
			queue1[q1]=p1;
			q1++;	
		}	
	

		else if(priority==1)
		{
			process p2;
			p2.input(q2,i);
			queue2[q2]=p2;
			q2++;
		}
	
		else if(priority==2)
		{
			process p3;
			p3.input(q3,i);
			queue3[q3]=p3;
			q3++;
		}
		
		else
		{
			cout<<"wrong priority entered";
			return 0;
		}
	}
	if(q1!=0)
	FCFS(queue1,q1);
	if(q2!=0)
	FCFS(queue2,q2);
	if(q3!=0)
	SRTF(queue3,q3);			
}
