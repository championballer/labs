#include<bits/stdc++.h>
using namespace std;

long long d=0,e1=0,e2=0,p=0,q=0;
pair<long long,long long> hsh;

long long modinv(long long a,long long n){
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

long long expn(long long A, long long B, long long C)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    // If B is even
    long long y;
    if (B % 2 == 0) {
        y = expn(A, B / 2, C);
        y = (y * y) % C;
    }

    // If B is odd
    else {
        y = A % C;
        y = (y * expn(A, B - 1, C) % C) % C;
    }

    return ((y + C) % C);
}

void key_gen(){
    cout<<"Enter a large prime : ";
    cin>>p;
    vector<int> vec;
    long long o = p-1;
    long long i = 2;
    while(o > 1){

        if(i*i > p-1){
            vec.push_back(o);
            break;
        }
        if(o%i == 0){
            vec.push_back(i);
            while(o%i == 0)
                o/=i;
        }
        i++;

    }
    cout<<"Enter q with from the following ";
    for(int i = 0;i<vec.size();i++)
        cout<<vec[i]<<" ";

    cin>>q;

    cout<<"Enter e0 : ";
    long long e0;
    cin>>e0;
    long long pw = (p-1)/q;
    e1 = expn(e0,pw,p);
    cout<<"e1 : "<<e1<<endl;
    while(d<1 ||d>p-2 ){
        cout<<"Enter d between 1 to "<<p-2<<" : ";
        cin>>d;
    }
    e2 = expn(e1,d,p);
    cout<<"e2 : "<<e2<<endl;
}

void sign(long long M,long long &S1,long long &S2){
    long long r=0;
    while(r<1 || r>q-1 ){
        cout<<"Enter a random number (1 to "<<q-1<<") : ";
        cin>>r;
        /*if(__gcd(r,q) != 1)
            r = 0;*/
    }
    S1 = expn(e1,r,p)%q;
    long long h;
    cout<<"Enter hash for given M : " ;//Can't use a generator
    cin>>h;
    long long hm = M%p;
    hsh = {hm,h};
    long long ri = modinv(r,q);
    S2 = ((h + d*S1)*ri)%q;
}
long long hashval(long long hm){
    if(hsh.first == hm)
        return hsh.second;
    else
        return 0;
}
bool verify(long long M,long long S1,long long S2){
    long long h = hashval(M);
    long long S2i = modinv(S2,q);
    long long pw1 = (h*S2i)%(q);
    long long ex1 = expn(e1,pw1,p);
    long long pw2 = (S1*S2i)%(q);
    long long ex2 = expn(e2,pw2,p);
    long long tmp = (ex1*ex2)%p;
    long long V = tmp%q;

    if(S1 == V)
        return 1;
    else
        return 0;
}

int main(){
    key_gen();
    long long M,S1,S2;
    cout<<endl;
    cout<<"Enter M for signing : ";
    cin>>M;
    sign(M,S1,S2);
    cout<<"S1 : "<<S1<<endl;
    cout<<"S2 : "<<S2<<endl;
    cout<<"Enter M,S1,S2 for verify : ";
    cin>>M>>S1>>S2;
    if(verify(M,S1,S2))
        cout<<"Accepted"<<endl;
    else
        cout<<"Rejected"<<endl;
    return 0;
}