#include<bits/stdc++.h> 

using namespace std;

class sample { 
public:
int a;
int b;
int c;
void inc_a(int& ua,int& m){
a++; ua++; m++;
}
void inc_b(int& ub,int& m){
b++; ub++;
m++; 
}
void inc_c(int& uc,int& m){ c++;
uc++; m++;
}
sample(int& ua, int&ub, int& uc,int& m){
a=0; b=0; c=0; ua++; ub++; uc++; m++;
}};

int main(){
int m=0;
int ua=0;
int ub=0;
int uc=0;
double lcom = 0;
sample s(ua,ub,uc,m);
s.inc_a(ua,m);
s.inc_b(ub,m);
s.inc_c(uc,m);
// cout<<m<<" "<<ua<<" "<<ub<<" "<<uc<<endl; 
int a=3;
lcom += ((double)(m-ua)+(m-ub)+(m-uc))/m; lcom /= a;
cout<<"attributes = "<<a<<endl; cout<<"methods = "<<m<<endl;
cout<<"ua = "<<ua<<endl;
cout<<"ub = "<<ub<<endl;
cout<<"lcom = "<<lcom<<endl;
}