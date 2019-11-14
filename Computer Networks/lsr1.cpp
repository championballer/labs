#include <bits/stdc++.h>
using namespace std;

long long d[100][100];

///LINK STATE ROUTING
void djkshtra(int C[5][5],int N,int source)
{
    d[source][source]=0;
    set<pair<long long,int> > S;
    S.insert({0,source});
    for(int i=0;i<N-1;i++)
    {
        auto it=S.begin();
        S.erase(it);
        int x=it->second;
        for(int i=0;i<N;i++)
            if(C[x][i]!=-1 && d[source][i]>d[source][x]+C[x][i])
            {
                auto it=S.find({d[source][i],i});
                if(it!=S.end())
                    S.erase(it);
                d[source][i]=d[source][x]+C[x][i];
                S.insert({d[source][i],i});
            }
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

    cout<<"LINK STATE ROUTING"<<endl;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            d[i][j]=INT_MAX;
    for(int i=0;i<N;i++)
        djkshtra(C,N,i);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }
}
