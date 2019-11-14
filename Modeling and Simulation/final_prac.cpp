#include<bits/stdc++.h>

using namespace std;

float square(int n)
{
	return n*n;
}

int main()
{
	
	cout<<"The null hypothesis : The observed numerical outcomes are uniformly distributed over the different categories."<<endl;
	cout<<"The alternate hypothesis: The observed numerical outcomes are not uniformly distributed over the different categories."<<endl;
	cout<<"Please enter total number of outcomes:";
	int N;
	cin>>N;
	cout<<"Please enter the number of categories:";
	int n;
	cin>>n;


	int * observed = new int[n];
	cout<<"Please enter the observed frequency for the "<<n<<" categories."<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>observed[i];
	}

	int expected_val = N/n;

	float * sq_diff = new float[n];

	for(int i=0;i<n;i++)
	{
		sq_diff[i] = square(observed[i]-expected_val)/expected_val;
	} 

	float chi_square = 0;

	for(int i=0;i<n;i++)
	{
		chi_square+=sq_diff[i];
	}

	cout<<"The chi-square statistic is "<<chi_square<<"."<<endl;

	float critical;
	cout<<"Please enter the critical value for chi-square distribution:";
	cin>>critical;

	if(chi_square<critical)
	{
		cout<<"The null hypothesis stands";
	}
	
	else
	{
		cout<<"The null hypothesis is rejected";
	}
}