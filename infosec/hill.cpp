#include <bits/stdc++.h>
using namespace std;

void multiply(char a[10][10],char key[10][10],int N,int M)
{
    char c[10][10];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            int sum=0;
            for(int k=0;k<M;k++)
                sum=(sum+(((a[i][k]-'a')%26)*((key[k][j]-'a')%26))%26)%26;
            c[i][j]=sum+'a';
        }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            a[i][j]=c[i][j];
}

// 9 7 11 13 4 7 5 6 2 21 14 9 3 23 21 8
void hillcipher()
{
    string s;
    cout<<"Enter String: ";
    cin>>s;
    cout<<"Enter M for M X M key matrix: ";
    int M;
    cin>>M;
    char key[10][10];
    cout<<"Enter the key matrix:";
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            cin>>key[i][j];
    char a[10][10];
    int row=ceil(double(s.size())/M);
    for(int i=0,index=0;i<row;i++)
        for(int j=0;j<M;j++,index++)
            if(index<s.size())
                a[i][j]=s[index];
            else
                a[i][j]='a';

    multiply(a,key,row,M);
    string output="";
    for(int i=0,index=0;i<row;i++)
        for(int j=0;j<M;j++,index++)
            if(index<s.size())
                output+=a[i][j];
    cout<<"Encrpyted String: "<<output<<endl;
}
int main()
{
    hillcipher();
}
