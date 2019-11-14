#include <bits/stdc++.h>
using namespace std;

void railfence_row()
{
    string s;
    int k;
    cout<<"Enter string: ";
    cin>>s;
    cout<<"KEY(2 for keyless): ";
    cin>>k;
    char a[k][s.size()];
    for(int i=0;i<k;i++)
        for(int j=0;j<s.size();j++)
            a[i][j]=0;
    int up=0,down=k-1,i=0,j=0,index=0;
    bool flag=true;
    while(index<s.size())
    {
        a[i][j]=s[index];
        index++;
        if(flag && i==down)
            flag=false;
        else if(!flag && i==up)
            flag=true;
        if(flag)
            i++;
        else
            i--;
        j++;
    }
    string output;
    for(int i=0;i<k;i++)
        for(int j=0;j<s.size();j++)
            if(a[i][j]!=0)
                output+=a[i][j];
    cout<<"ENCRYPTED String: "<<output<<endl;

    s.clear();

    for(int i=0;i<k;i++)
        for(int j=0;j<output.size();j++)
            a[i][j]=0;
    up=0;
    down=k-1;
    i=0;
    j=0;
    index=0;

    flag=true;
    while(index<output.size())
    {
        a[i][j]='*';
        index++;
        if(flag && i==down)
            flag=false;
        else if(!flag && i==up)
            flag=true;
        if(flag)
            i++;
        else
            i--;
        j++;
    }

    index=0;
    for(int i=0;i<k;i++)
        for(int j=0;j<output.size();j++)
            if(a[i][j]=='*')
            {
                a[i][j]=output[index];
                index++;
            }

    up=0;
    down=k-1;
    i=0;
    j=0;
    index=0;

    flag=true;
    while(index<output.size())
    {
        s+=a[i][j];
        index++;
        if(flag && i==down)
            flag=false;
        else if(!flag && i==up)
            flag=true;
        if(flag)
            i++;
        else
            i--;
        j++;
    }

    cout<<"DECRYTED String: "<<s<<endl;
}

void railfence_column()
{
    string s;
    int k;
    cout<<"Enter string: ";
    cin>>s;
    cout<<"KEY(2 for keyless): ";
    cin>>k;
    char a[s.size()][k];
    for(int i=0;i<s.size();i++)
        for(int j=0;j<k;j++)
            a[i][j]=0;
    int up=0,down=k-1,i=0,j=0,index=0;
    bool flag=true;
    while(index<s.size())
    {
        a[j][i]=s[index];
        index++;
        if(flag && i==down)
            flag=false;
        else if(!flag && i==up)
            flag=true;
        if(flag)
            i++;
        else
            i--;
        j++;
    }
    string output;
    for(int i=0;i<k;i++)
        for(int j=0;j<s.size();j++)
            if(a[j][i]!=0)
                output+=a[j][i];
    cout<<"ENCRYPTED String: "<<output<<endl;

    s.clear();

    for(int i=0;i<output.size();i++)
        for(int j=0;j<k;j++)
            a[i][j]=0;
    up=0;
    down=k-1;
    i=0;
    j=0;
    index=0;

    flag=true;
    while(index<output.size())
    {
        a[j][i]='*';
        index++;
        if(flag && i==down)
            flag=false;
        else if(!flag && i==up)
            flag=true;
        if(flag)
            i++;
        else
            i--;
        j++;
    }

    index=0;
    for(int i=0;i<k;i++)
        for(int j=0;j<output.size();j++)
            if(a[j][i]=='*')
            {
                a[j][i]=output[index];
                index++;
            }

    up=0;
    down=k-1;
    i=0;
    j=0;
    index=0;

    flag=true;
    while(index<output.size())
    {
        s+=a[j][i];
        index++;
        if(flag && i==down)
            flag=false;
        else if(!flag && i==up)
            flag=true;
        if(flag)
            i++;
        else
            i--;
        j++;
    }
    cout<<"DECRYTED String: "<<s<<endl;
}
int main()
{
    railfence_column();
}
