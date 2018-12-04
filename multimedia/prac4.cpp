#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
 int freq;
 char data;
 struct node *left,*right;
}node;
node *newnode(char data,int freq)
{
 node *p=new node;
 p->data=data;
 p->freq = freq;
 p->left=p->right=NULL;
 return p;
}
void printArr(int arr[], int n)
{
 int i;
 for (i = 0; i < n; i++)
 cout<<arr[i]<<" ";
 cout<<'\n';
}
void printCodes(node *root, int arr[], int top)
{
 if (root->left)
 {
 arr[top] = 0;
 printCodes(root->left, arr, top + 1);
 }
 if (root->right)
 {
 arr[top] = 1;
 printCodes(root->right, arr, top + 1);
 }
 if (!root->right && !root->left)
 {
 cout<<root->data<<" ";
 printArr(arr, top);
 }
}
int height(node *root)
{
 if(root==NULL)
 return 0;
 return 1 + max(height(root->left),height(root->right));
}
void search(node *root,char ch,node *&p)
{
 if(root==NULL)
 return;
 if(root->data==ch)
 p=root;
 search(root->left,ch,p);
 search(root->right,ch,p);
}
int updatefreq(node *root)
{
 if(root==NULL)
 return 0;
 if(root->left==NULL && root->right==NULL)
 return root->freq;
 root->freq = updatefreq(root->left) + updatefreq(root->right);
 return root->freq;
}
void swapnodedata(node *a,node *b)
{
 node *tempn;
 char tempc;
 int tempf;
 //char
 tempc=a->data;
 a->data=b->data;
 b->data=tempc;
 //freq;
 tempf=a->freq;
 a->freq=b->freq;
 b->freq=tempf;
 //left
 tempn=a->left;
 a->left=b->left;
 b->left=tempn;
 //right
 tempn=a->right;
 a->right=b->right;
 b->right=tempn;
}
bool anomalyswap(vector<node*> &rlo)
{
 int n=(int)rlo.size(),i,j;
 for(i=0;i<n;i++)
 {
 for(j=n-1;j>i;j--)
 {
 if(rlo[i]->freq>rlo[j]->freq)
 {
 swapnodedata(rlo[i],rlo[j]);
 return true;
 }
 }
 }
 return false;
}
bool reverselevelanomalyswap(node *root)
{
 vector<node*> rlo;
 stack<node*> s;
 queue<node*> q;
 node *p=root;
 q.push(p);
 while(!q.empty())
 {
 p=q.front();
 q.pop();
 s.push(p);
 if(p->right)
 q.push(p->right);
 if(p->left)
 q.push(p->left);
 }
 while(!s.empty())
 {
 rlo.push_back(s.top());
 s.pop();
 }
 return anomalyswap(rlo);
}
void huffmanadaptive(node *root,char ch)
{
 node *p=NULL;
 search(root,ch,p);
 if(p==NULL)
 {
 search(root,'#',p);
 p->data='$'; //different from hash
 p->left=newnode('#',0);
 p->right=newnode(ch,1);
 }
 else
 p->freq++;
 updatefreq(root);
 while(reverselevelanomalyswap(root))
 updatefreq(root);
 int h=height(root);
 int arr[h];
 printCodes(root,arr,0);
}
int main()
{
 cout<<"Enter running stream of characters"<<"\n";
 char ch,s;
 node *root=newnode('#',0);
 do
 {
 cin>>s;
 huffmanadaptive(root,s);
 cout<<"Do you want to continue(y/n): ";
 cin>>ch;
 }while(ch=='y'||ch=='Y');
 return 0;
}