#include<bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m,int processSize[], int n)
{
    int allocation[n];

    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t"<< processSize[i] << "\t\t";
        if (allocation[i] != -1)cout << allocation[i] + 1;
        else cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{

	int m,n;
	cout<<"Please enter the number of blocks and processes:"<<endl;
	cin>>m>>n;
    	int * blockSize = new int[m];
	for(int i=0;i<m;i++)
	{
		cin>>blockSize[i];
	}
	
	int  * processSize = new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>processSize[i];
	}

       	firstFit(blockSize, m, processSize, n);

    return 0 ;
}

