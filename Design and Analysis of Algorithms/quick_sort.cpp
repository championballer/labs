#include<bits/stdc++.h>

using namespace std;

int partition(int arr[],int size)
{
    int x=arr[0];
    int countSmall=0;
    
    for(int i=1;i<size;i++)
    {
        if(arr[i]<arr[0])
        {
            countSmall++;
        }
    }
    
    arr[0]=arr[countSmall];
    arr[countSmall]=x;
    
    int z=0;
    int j=size-1;
    
    while(z<countSmall && j>countSmall)
    {
        if(arr[z]<x)
        {
            z++;
        }
        
        else if(arr[j]>=x)
        {
            j--;
        }
        
        else {
            int temp=arr[z];
            arr[z]=arr[j];
            arr[j]=temp;
            z++;
            j--;
        }
        
    }
    
    return countSmall;
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size==0 || size==1)
    {
        return;
    }
    
    int pos=partition(input,size);
    
    quickSort(input,pos);
    quickSort(input+pos+1,size-pos-1);
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

    quickSort(arr,size);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}