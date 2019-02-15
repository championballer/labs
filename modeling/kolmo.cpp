#include <bits/stdc++.h>

using namespace std;

float del_pos(float a[], int n)
{
    float gt=0;
    for(int i=0;i<n;i++)
    {
        float x = ((i+1)/(float)n)-a[i];
        if(x>gt)
        {
            gt=x;
        }
    }
    return gt;
}

float del_neg(float a[], int n)
{
    float grt=0;
    for(int i=0;i<n;i++)
    {
        float x = a[i]-(i/(float)n);
        if(x>grt)
        {
            grt=x;
        }
    }
    return grt;
}

int main()
{
    int n;
    cout << "Enter the number of random numbers: ";
    cin>>n;
    float arr[n];
    cout<<"Enter the random numbers:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    float dal;
    cout<<"Enter the value of D-alpha: ";
    cin>>dal;
    cout<<"\nHypothesis: Given random numbers are uniformly distributed."<<endl;
    float pos_d= del_pos(arr,n);
    float neg_d= del_neg(arr,n);
    float del= max(pos_d,neg_d);
    //cout<<"D+ = "<<pos_d;
    //cout<<"D- = "<<neg_d;
    cout<<"D = "<<del<<endl;

    if(del<dal)
        cout<<"\nHypothesis is true.";
    else
        cout<<"\nHypothesis is false.";

    return 0;
}