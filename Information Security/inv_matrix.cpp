
#include <bits/stdc++.h>
using namespace std;


int modinv(int a,int n){
    long long r1 = n,r2 = a,t1 = 0,t2 = 1;
    while(r2>0){
        long long q = r1/r2;
        long long r = r1%r2;
        r1 = r2;
        r2 = r;
        long long t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }

    return (n+t1)%n;
}
void cofac(int a[100][100],int p,int q,int n,int temp[100][100]){
    int si = 0,sj = 0;
    for(int i = 0;i<n;i++){
        if(i == p)
            continue;
        for(int j = 0;j<n;j++){
            if(j == q)
                continue;
            temp[si][sj] = a[i][j];
            sj++;
        }
        sj = 0;
        si++;
    }
}
int det(int a[100][100],int n){
    if(n == 1)
        return a[0][0];
    int sum = 0,sig = 1;
    for(int i = 0;i < n;i++){
        int temp[100][100];
        cofac(a,0,i,n,temp);
        int cd = det(temp,n-1);
        sum += sig*cd*a[0][i];
        sig *= -1;
    }
    return sum;
}
void adjmat(int a[100][100],int adj[100][100],int n){
    int sig = 1;
    int t[100][100];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int temp[100][100];
            cofac(a,i,j,n,temp);
            t[i][j] = sig*det(temp,n-1);
            sig *= -1;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            adj[i][j] = t[j][i];
        }
    }
}
void matmul(int a[100][100],int b[100][100],int res[100][100],int n,int m,int o,int M){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<o;j++){
            res[i][j] = 0;
            for(int k=0;k<m;k++){
                res[i][j] = (res[i][j] + a[i][k]*b[k][j])%M;
            }
        }
    }
}
int main()
{
	int a[100][100];
	int n;
	cout<<"Enter number of equations ";
	cin>>n;
	cout<<"Enter coefficients : "<<endl;
	for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++)
            cin>>a[i][j];
	}
	int M;
    cout<<"Enter base of mod : ";
    cin>>M;
    cout<<"Enter d's of each equation : "<<endl;
    int d[100][100];
    for(int i = 0;i<n;i++){
        cin>>d[i][0];
        d[i][0] = d[i][0]%M;
    }
    int dt = det(a,n)%M;
    if(__gcd(dt,M) != 1){
        cout<<"Solution does not exist";
    }
    else{
        int dti = modinv(dt,M);
        int adj[100][100];
        adjmat(a,adj,n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                adj[i][j] = (dti*adj[i][j])%M;
            }
        }
        int res[100][100];
        matmul(adj,d,res,n,n,1,M);
        for(int i = 0;i<n;i++){
                cout<<(M+res[i][0])%M;
            cout<<endl;
        }
    }
    return 0;
}
/*
3
3 1 -1
2 -2 0
1 2 -1
*/
