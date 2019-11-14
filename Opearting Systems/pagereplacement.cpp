#include <bits/stdc++.h>
using namespace std;

void FIFO(int arr[100],int N,int K)
{
    queue<int> Q;
    int counter=0;
    for(int i=0;i<N;i++)
    {
        queue<int> temp=Q;
        cout<<"CONTENTS: ";
        bool found=false;
        while(!temp.empty())
        {
            if(temp.front()==arr[i])
                found=true;
            cout<<temp.front()<<" ";
            temp.pop();
        }
        if(found)
        {
            cout<<endl;
            continue;
        }
        counter++;
        cout<<"     PAGE FAULT"<<endl;
        if(Q.size()==K)
            Q.pop();
        Q.push(arr[i]);
    }
    cout<<counter<<endl;
}

void LRU(int arr[100],int N,int K)
{
    int frame[K];
    for(int i=0;i<K;i++)
        frame[i]=-1;
    for(int i=0;i<N;i++)
    {
        bool pagehit=false;
        cout<<"CONTENTS: ";
        for(int j=0;j<K;j++)
            if(frame[j]!=-1)
                cout<<frame[j]<<" ";
        for(int j=0;j<K;j++)
            if(arr[i]==frame[j])
            {
                for(int k=j;k>0;k--)
                    frame[k]=frame[k-1];
                frame[0]=arr[i];
                pagehit=true;
                break;
            }
        if(pagehit)
        {
            cout<<endl;
            continue;
        }
        cout<<"     PAGE FAULT"<<endl;
        for(int j=K-1;j>0;j--)
            frame[j]=frame[j-1];
        frame[0]=arr[i];
    }
    cout<<endl;
}

void OPTIMAL(int arr[100],int N,int K)
{
    queue<int> Q;
    for(int i=0;i<N;i++)
    {
        queue<int> t=Q;
        cout<<"CONTENTS: ";
        bool found=false;
        while(!t.empty())
        {
            if(t.front()==arr[i])
                found=true;
            cout<<t.front()<<" ";
            t.pop();
        }
        if(found)
        {
            cout<<endl;
            continue;
        }
        cout<<"     PAGE FAULT"<<endl;
        if(Q.size()==K)
        {
            bool mark[100]={0};
            queue<int> t=Q;
            while(!t.empty())
            {
                mark[t.front()]=1;
                t.pop();
            }
            int page_to_replace=-1;
            for(int j=i+1;j<N;j++)
                if(mark[arr[j]])
                {
                    page_to_replace=arr[j];
                    mark[arr[j]]=0;
                }
            t=Q;
            while(!t.empty())
            {
                if(mark[t.front()])
                {
                    page_to_replace=t.front();
                    break;
                }
                t.pop();
            }
            while(!t.empty())
                t.pop();

            while(!Q.empty())
            {   
               if(Q.front()!=page_to_replace)
                    t.push(Q.front());
                Q.pop();
            }
            t.push(arr[i]);
            Q=t;
        }
        else
            Q.push(arr[i]);
    }
}

void LFU(int arr[100],int N,int K)
{
    int counter[100]={0};
    queue<int> Q;
    for(int i=0;i<N;i++)
    {
        queue<int> t=Q;
        cout<<"CONTENTS: ";
        bool found=false;
        while(!t.empty())
        {
            if(t.front()==arr[i])
                found=true;
            cout<<t.front()<<" ";
            t.pop();
        }
        if(found)
        {
            counter[arr[i]]++;
            cout<<endl;
            continue;
        }
        cout<<"     PAGE FAULT"<<endl;
        if(Q.size()==K)
        {
            int page_to_replace,min_value=INT_MAX;
            queue<int> t=Q;
            while(!t.empty())
            {
                if(counter[t.front()]<min_value)
                {
                    min_value=counter[t.front()];
                    page_to_replace=t.front();
                }   
                t.pop();
            }

            while(!Q.empty())
            {   
               if(Q.front()!=page_to_replace)
                    t.push(Q.front());
                Q.pop();
            }
            t.push(arr[i]);
            Q=t;
            counter[arr[i]]++;
        }
        else
        {
            Q.push(arr[i]);
            counter[arr[i]]++;
        }
    }
    cout<<endl;
}

void MFU(int arr[100],int N,int K)
{
    int counter[100]={0};
    queue<int> Q;
    for(int i=0;i<N;i++)
    {
        queue<int> t=Q;
        cout<<"CONTENTS: ";
        bool found=false;
        while(!t.empty())
        {
            if(t.front()==arr[i])
                found=true;
            cout<<t.front()<<" ";
            t.pop();
        }
        if(found)
        {
            counter[arr[i]]++;
            cout<<endl;
            continue;
        }
        cout<<"     PAGE FAULT"<<endl;
        if(Q.size()==K)
        {
            int page_to_replace,max_value=INT_MIN;
            queue<int> t=Q;
            while(!t.empty())
            {
                if(counter[t.front()]>max_value)
                {
                    max_value=counter[t.front()];
                    page_to_replace=t.front();
                }   
                t.pop();
            }

            while(!Q.empty())
            {   
               if(Q.front()!=page_to_replace)
                    t.push(Q.front());
                Q.pop();
            }
            t.push(arr[i]);
            Q=t;
            counter[arr[i]]++;
        }
        else
        {
            Q.push(arr[i]);
            counter[arr[i]]++;
        }
    }
    cout<<endl;
}

int main()
{
    int choice;
    cout<<"Enter Choice"<<endl<<"(1) FIFO (2) LRU (3) OPTIMAL (4) LFU (5) MFU (6) EXIT"<<endl;
    cin>>choice;
    int N;
    cout<<"Number Of References: ";
    cin>>N;
    int arr[100];
    cout<<"Enter String"<<endl;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    int K;
    cout<<"Frame Size: ";
    cin>>K;
    while(choice!=6)
    {
        switch(choice)
        {
            case 1: FIFO(arr,N,K);
                break;
            case 2: LRU(arr,N,K);
                break;
            case 3: OPTIMAL(arr,N,K);
                break;
            case 4: LFU(arr,N,K);
                break;
            case 5: MFU(arr,N,K);
        }
        cin>>choice;
    }
}