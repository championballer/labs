#include<bits/stdc++.h>

using namespace std;

void inplaceHeapSort(int input[], int n){
    
	for(int i=0;i<n;i++)
     {
       int ci=i;
       int pi=(ci-1)/2;
       while(ci!=0)
       {
         if(input[ci]<input[pi])
         {
           int temp=input[ci];
           input[ci]=input[pi];
           input[pi]=temp;
           ci=pi;
           pi=(ci-1)/2;
         }
         
         else break;
       }
     }
  
  	for(int i=n-1;i>=0;i--)
    {
      int temp=input[0];
      input[0]=input[i];
      input[i]=temp;
      
      int pi=0;
      int ci1=(2*pi)+1;
      int ci2=(2*pi)+2;
      int min=0;
      	while(ci1<i)
      	{
        	if(ci1<i && ci2>=i)
        	{
          		min=ci1;
        	}
        
        	else if(input[ci1]<input[ci2])
        	{
          		min=ci1;
        	}
        
        	else min=ci2;
        
        	if(input[min]<input[pi])
        	{
          	int tempi=input[min];
          	input[min]=input[pi];
          	input[pi]=tempi;
          	pi=min;
          	ci1=(2*pi)+1;
          	ci2=(2*pi)+2;
        	}
        
        	else break;
      	}
      
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

    inplaceHeapSort(arr,size);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}