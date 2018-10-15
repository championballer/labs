#include <bits/stdc++.h>
using namespace std;

///DISTANCE VECTOR ROUTING
long long d[100][100];
void bellman_ford(int C[5][5],int source,int N)
{
    ///DISTRIBUTE ROUTING TABLE OF source TO ALL ADJACENT NODES
    for(int i=0;i<N;i++)
        if(C[source][i]!=-1 && i!=source)
        {
            ///NEIGHBOUR
            bool flag=false;
            for(int j=0;j<N;j++)
            {
                if(d[i][j]>d[i][source]+d[source][j])
                {
                    d[i][j]=d[i][source]+d[source][j];
                    flag=true;
                }
            }
            ///IF ROUTING TABLE OF NEIGHBOUR IS UPDATED, SPREAD IT TO ITS NEIGHBOURS
            if(flag)
                bellman_ford(C,i,N);
        }
}

int main()
{
    int N;
    cout<<"Enter number of nodes"<<endl;
    cin>>N;
    int C[5][5];
    cout<<"Enter cost of various edges"<<endl;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>C[i][j];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(C[i][j]==-1)
                d[i][j]=INT_MAX;
            else
                d[i][j]=C[i][j];

    cout<<"DISTANCE VECTOR ROUTING"<<endl;
    for(int i=0;i<N;i++)
        bellman_ford(C,i,N);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }
}

