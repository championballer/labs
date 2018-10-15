#include<bits/stdc++.h>
#include"soduko_solver.h"

using namespace std;

int board[9][9];

void print_message()
{

}

void print_grid()
{

	cout<<"  ";
	for(int i=0;i<9;i++)cout<<i;
	cout<<endl;
	for(int i=0;i<9;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<9;j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}

int main()
{

	print_message();
	randomise();
	int difficulty;

	int unique_entries;
	if(difficulty == 1)
		unique_entries = 18;
	else if(difficulty==2)
		unique_entries = 15;
	else unique_entries = 12;

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)board[i][j]=0;
	}

	for(int i=0;i<unique_entries;i++)
	{

	}
}