#include<bits/stdc++.h>

using namespace std;

int binarySearch(int input[], int size, int element) {
    // Write your code here
    if(size==0)
    {
        return -1;
    }
    int middle=0;
    if(size%2==0)
    {
        middle=size/2;
        middle-=1;
    }
    
    else{
      middle=size/2;
    } 
    
    
    if(input[middle]==element){
        return middle;
    }
    
    else if(input[middle]>element)
    {
        int x=binarySearch(input,middle,element);
        return x;
    }
    
    else{
        
        int x=binarySearch(input+middle+1,size-middle-1,element);
        if(x==-1)
        {
            return x;
        }
        
        else return x+middle+1;
    }
    
    
    
}

int main()
{
    int size;
    cout<<"Please enter the size of the array:";
    cin>>size;
    int * arr = new int[size];

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int element;
    cout<<"Please enter the element to find:";
    cin>>element;

    cout<<binarySearch(arr,size,element)<<endl;
}
