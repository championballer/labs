#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int seq[n];
    int age[n];
    cout<<"Enter sequence number: ";
    for(int i=0;i<n;i++)
        cin>>seq[i];
    cout<<"Enter age: ";
    for(int i=0;i<n;i++)
        cin>>age[i];
    int m;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<pair<int,int>> grph[n];
    cout<<"Enter Graph:"<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        grph[u].push_back({v,w});
        grph[v].push_back({u,w});
    }
    int src;
    cout<<"Enter source: ";
    cin>>src;
    cout<<endl<<endl;
    cout<<"LSP=>"<<endl;
    cout<<"Name: "<<src<<endl;
    cout<<"Sequence Number: "<<seq[src]<<endl;
    cout<<"Age: "<<age[src]<<endl;
    cout<<"Adjacency List:"<<endl;
    for(int i=0;i<grph[src].size();i++)
        cout<<grph[src][i].first<<" "<<grph[src][i].second<<endl;
    set<pair<int,int>> q;
    int *dist = new int[n];
    bool *sptset = new bool[n];
    for(int i=0;i<n;i++)
    {
        q.insert({INT_MAX,i});
        dist[i] = INT_MAX;
        sptset[i] = false;
    }
    auto it = q.find({dist[src],src});
    q.erase(it);
    dist[src] = 0;
    q.insert({dist[src],src});
    for(int i=0;i<n;i++)
    {
        pair<int,int> u = *q.begin();
        q.erase(u);
        sptset[u.second] = true;
        for(int j=0;j<grph[u.second].size();j++)
        {
            pair<int,int> e = grph[u.second][j];
            if(!sptset[e.first] && dist[e.first]>dist[u.second]+e.second)
            {
                auto it = q.find({dist[e.first],e.first});
                q.erase(it);
                dist[e.first] = dist[u.second]+e.second;
                q.insert({dist[e.first],e.first});
            }
        }
    }
    cout<<endl<<endl;
    cout<<"Shortest Path Tree:"<<endl;
    for(int i=0;i<n;i++)
        cout<<i<<" "<<dist[i]<<endl;
    return 0;
}
