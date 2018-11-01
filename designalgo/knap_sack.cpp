#include<bits/stdc++.h>

using namespace std;
  
int knap_sack(int w_knapsack, int * weight, int * val, int n) 
{ 
   int i, w; 
   int K[n+1][w_knapsack+1]; 
  
  for (i = 0; i <= n; i++) 
  { 
      for (w = 0; w <= w_knapsack; w++) 
      { 
          if(i==0 || w==0) 
              K[i][w] = 0; 
          else if (weight[i-1] <= w) 
                K[i][w] = max(val[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]); 
          else
                K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][w_knapsack]; 
} 
  
int main() 
{ 

    int iter=1;
    while(iter)
    {
        int size;

        cout<<"Please enter size:";
        cin>>size;

        int * val = new int[size];
        int * weight = new int[size];

        cout<<"Enter values with spaces:";
        for(int i=0;i<size;i++)
        {
        cin>>val[i];
        }

        cout<<"Enter corresponding weights with spaces:";
        for(int i=0;i<size;i++)
        {
        cin>>weight[i];
        }

        int w_knapsack;
        cout<<"Please enter the weight of the knap_sack:";
        cin>>w_knapsack;

        cout<<knap_sack(w_knapsack,weight,val,size)<<endl;  

        cout<<"Want to try again(1:y, 0:n?"<<endl;
        cin>>iter;
    }
    
     
} 