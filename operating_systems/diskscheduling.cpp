#include <bits/stdc++.h>
using namespace std;

void FCFS(int arr[100],int N,int min_cyl,int max_cyl,int arm_pos)
{
	vector<int> ans;
	ans.push_back(arm_pos);
	for(int i=0;i<N;i++)
		ans.push_back(arr[i]);
	int cylinder=0;
	for(int i=1;i<ans.size();i++)
		cylinder+=abs(ans[i]-ans[i-1]);
	cout<<"MOVEMENTS: ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<"CYLINDERS MOVED: "<<cylinder<<endl<<endl;
}

void SSTF(int arr[100],int N,int min_cyl,int max_cyl,int arm_pos)
{
	bool mark[max_cyl+1]={0};
	for(int i=0;i<N;i++)
		mark[arr[i]]=1;
	mark[arm_pos]=1;
	vector<int> ans;
	while(1)
	{
		ans.push_back(arm_pos);
		mark[arm_pos]=0;
		int right=1000000,left=-1000000;
		for(int i=arm_pos+1;i<=max_cyl;i++)
			if(mark[i])
			{
				right=i;
				break;
			}
		for(int i=arm_pos-1;i>=min_cyl;i--)
			if(mark[i])
			{
				left=i;
				break;
			}
		if(left==-1000000 && right==1000000)
			break;

		if(right-arm_pos < arm_pos-left)
			arm_pos=right;
		else
			arm_pos=left;
	}

	int cylinder=0;
	for(int i=1;i<ans.size();i++)
		cylinder+=abs(ans[i]-ans[i-1]);
	cout<<"MOVEMENTS: ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<"CYLINDERS MOVED: "<<cylinder<<endl<<endl;
}

void SCAN(int arr[100],int N,int min_cyl,int max_cyl,int arm_pos,int pre_arm)
{
	vector<int> ans;
	bool mark[max_cyl+1]={0};
	for(int i=0;i<N;i++)
		mark[arr[i]]=1;
	mark[arm_pos]=1;
	if(pre_arm<arm_pos)
	{
		mark[max_cyl]=1;
		for(int i=arm_pos;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=max_cyl;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	else
	{
		mark[min_cyl]=1;
		for(int i=arm_pos;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=min_cyl;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	int cylinder=0;
	for(int i=1;i<ans.size();i++)
		cylinder+=abs(ans[i]-ans[i-1]);
	cout<<"MOVEMENTS: ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<"CYLINDERS MOVED: "<<cylinder<<endl<<endl;
}

void CSCAN(int arr[100],int N,int min_cyl,int max_cyl,int arm_pos,int pre_arm)
{
	vector<int> ans;
	bool mark[max_cyl+1]={0};
	for(int i=0;i<N;i++)
		mark[arr[i]]=1;
	mark[arm_pos]=1;
	mark[max_cyl]=1;
	mark[min_cyl]=1;
	if(pre_arm<arm_pos)
	{
		for(int i=arm_pos;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=min_cyl;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	else
	{
		for(int i=arm_pos;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=max_cyl;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	int cylinder=0;
	for(int i=1;i<ans.size();i++)
		cylinder+=abs(ans[i]-ans[i-1]);
	cout<<"MOVEMENTS: ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<"CYLINDERS MOVED: "<<cylinder<<endl<<endl;
}

void LOOK(int arr[100],int N,int min_cyl,int max_cyl,int arm_pos,int pre_arm)
{
	vector<int> ans;
	bool mark[max_cyl+1]={0};
	for(int i=0;i<N;i++)
		mark[arr[i]]=1;
	mark[arm_pos]=1;
	if(pre_arm<arm_pos)
	{
		for(int i=arm_pos;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=max_cyl;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	else
	{
		for(int i=arm_pos;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=min_cyl;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	int cylinder=0;
	for(int i=1;i<ans.size();i++)
		cylinder+=abs(ans[i]-ans[i-1]);
	cout<<"MOVEMENTS: ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<"CYLINDERS MOVED: "<<cylinder<<endl<<endl;
}

void CLOOK(int arr[100],int N,int min_cyl,int max_cyl,int arm_pos,int pre_arm)
{
	vector<int> ans;
	bool mark[max_cyl+1]={0};
	for(int i=0;i<N;i++)
		mark[arr[i]]=1;
	mark[arm_pos]=1;
	if(pre_arm<arm_pos)
	{
		for(int i=arm_pos;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=min_cyl;i<=max_cyl;i++)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	else
	{
		for(int i=arm_pos;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
		for(int i=max_cyl;i>=min_cyl;i--)
			if(mark[i])
			{
				ans.push_back(i);
				mark[i]=false;
			}
	}
	int cylinder=0;
	for(int i=1;i<ans.size();i++)
		cylinder+=abs(ans[i]-ans[i-1]);
	cout<<"MOVEMENTS: ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	cout<<"CYLINDERS MOVED: "<<cylinder<<endl<<endl;
}

int main()
{
	int choice;
	cout<<"Enter Choice"<<endl<<"(1) FCFS (2) SSTF (3) SCAN (4) C-SCAN (5) LOOK (6) C-LOOK (7) EXIT"<<endl;
	cin>>choice;
	int min_cyl,max_cyl,arm_pos,pre_arm;
	cout<<"Enter minimum cylinder, maximum cylinder, arm position and previous arm position"<<endl;
	cin>>min_cyl>>max_cyl>>arm_pos>>pre_arm;
	int N;
	cout<<"Number of references: ";
	cin>>N;
	int arr[100];
	cout<<"References"<<endl;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	while(choice!=7)
	{
		switch(choice)
		{
			case 1: FCFS(arr,N,min_cyl,max_cyl,arm_pos);
					break;
			case 2: SSTF(arr,N,min_cyl,max_cyl,arm_pos);
					break;
			case 3: SCAN(arr,N,min_cyl,max_cyl,arm_pos,pre_arm);
					break;
			case 4: CSCAN(arr,N,min_cyl,max_cyl,arm_pos,pre_arm);
					break;
			case 5: LOOK(arr,N,min_cyl,max_cyl,arm_pos,pre_arm);
					break;
			case 6: CLOOK(arr,N,min_cyl,max_cyl,arm_pos,pre_arm);
		}
		cin>>choice;
	}
}