#include <bits/stdc++.h>
using namespace std;

void first_fit(int arr[100], int N, int process[100], int K)
{
	int temp[100];
	for(int i=0;i<N;i++)
		temp[i]=arr[i];

	cout<<"PROCESS\t\tMEMORY\t\t\t\t\tBLOCK"<<endl;;
	for(int i=0;i<K;i++)
	{
		cout<<process[i]<<"\t\t";
		for(int j=0;j<N;j++)
			printf("%4d ",arr[j]);
		cout<<"\t\t";
		bool found=false;
		for(int j=0;j<N;j++)
			if(arr[j]>=process[i])
			{
				cout<<arr[j]<<endl;
				arr[j]-=process[i];
				found=true;
				break;
			}
		if(!found)
			cout<<"NO SPACE AVAILABLE"<<endl;
	}
	cout<<endl;
	for(int i=0;i<N;i++)
		arr[i]=temp[i];
}

void best_fit(int arr[100], int N, int process[100], int K)
{
	int temp[100];
	for(int i=0;i<N;i++)
		temp[i]=arr[i];
	
	cout<<"PROCESS\t\tMEMORY\t\t\t\t\tBLOCK"<<endl;;
	for(int i=0;i<K;i++)
	{
		cout<<process[i]<<"\t\t";
		for(int j=0;j<N;j++)
			printf("%4d ",arr[j]);
		cout<<"\t\t";
		int ans=-1,min_value=INT_MAX;
		for(int j=0;j<N;j++)
			if(arr[j]>=process[i] && min_value>arr[j]-process[i])
			{
				ans=j;
				min_value=arr[j]-process[i];
			}

		if(ans==-1)
			cout<<"NO SPACE AVAILABLE"<<endl;
		else
		{
			arr[ans]-=process[i];
			cout<<arr[ans]<<endl;
		}
	}
	cout<<endl;
	for(int i=0;i<N;i++)
		arr[i]=temp[i];
}

void worst_fit(int arr[100], int N, int process[100], int K)
{
	int temp[100];
	for(int i=0;i<N;i++)
		temp[i]=arr[i];
	
	cout<<"PROCESS\t\tMEMORY\t\t\t\t\tBLOCK"<<endl;;
	for(int i=0;i<K;i++)
	{
		cout<<process[i]<<"\t\t";
		for(int j=0;j<N;j++)
			printf("%4d ",arr[j]);
		cout<<"\t\t";
		int ans=-1,max_value=INT_MIN;
		for(int j=0;j<N;j++)
			if(arr[j]>=process[i] && max_value<arr[j]-process[i])
			{
				ans=j;
				max_value=arr[j]-process[i];
			}

		if(ans==-1)
			cout<<"NO SPACE AVAILABLE"<<endl;
		else
		{
			arr[ans]-=process[i];
			cout<<arr[ans]<<endl;
		}
	}
	cout<<endl;
	for(int i=0;i<N;i++)
		arr[i]=temp[i];
}

int main()
{
	int N;
	cout<<"NUMBER OF FREE BLOCKS: ";
	cin>>N;
	int arr[100];
	cout<<"Size of free blocks: "<<endl;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	int K;
	cout<<"NUMBER OF PROCESSES: ";
	cin>>K;
	int process[100];
	cout<<"Size of processes: "<<endl;
	for(int i=0;i<K;i++)
		cin>>process[i];
	first_fit(arr,N,process,K);
	best_fit(arr,N,process,K);
	worst_fit(arr,N,process,K);
}