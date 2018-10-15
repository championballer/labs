#include<bits/stdc++.h>
using namespace std;
 
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
 
    memset(allocation, -1, sizeof(allocation));
 
    for (int i=0; i<n; i++)
    {
        int bestIndex = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIndex == -1)
                    bestIndex = j;
                else if (blockSize[bestIndex] > blockSize[j])
                    bestIndex = j;
            }
        }
 
        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

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
    	int * blockSize1 = new int[m];
	int * blockSize2 = new int[m];
	for(int i=0;i<m;i++)
	{
		cin>>blockSize1[i];
		blockSize2[i]=blockSize1[i];
	}
	
	int  * processSize1 = new int[n];
	int  * processSize2 = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>processSize1[i];
		processSize2[i]=processSize1[i];;
		
	}

       	bestFit(blockSize1, m, processSize1, n);
	firstFit(blockSize2,m,processSize2,n);
    return 0 ;


    
}

