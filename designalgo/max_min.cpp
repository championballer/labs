#include<bits/stdc++.h>

using namespace std;

pair<int,int> max_min(int * arr, int n)
{
	pair<int,int> ans;
	if(n==0)
	{
		ans.first = INT_MIN;
		ans.second = INT_MAX;

		return ans;
	}

	if(n==1)
	{
		ans.first = arr[0];
		ans.second = arr[0];

		return ans;
	}

	int middle = n/2;

	pair<int,int> fsans = max_min(arr,middle);
	pair<int,int> ssans = max_min(arr+middle,n-middle);

	ans.first = max(fsans.first,ssans.first);
	ans.second = min(fsans.second,ssans.second);

	return ans;
}

int main()
{
	int n;
	cout<<"Enter size of array:";
	cin>>n;

	int * arr = new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	pair<int,int> mm = max_min(arr,n);

	cout<<"max:"<<mm.first<<" "<<"min:"<<mm.second<<endl;
}