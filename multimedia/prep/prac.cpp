#include <bits/stdc++.h>
using namespace std;
#include"node.h"

//prints array
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

void dynamic(node *root,char ch)
{
 	node *p=NULL;
 	//search for node's presence in tree
 	search(root,ch,p);

 	if(p==NULL)
 	{
 		search(root,'#',p);
 		p->data='$';
 		p->left=new node('#',0);
 		p->right=new node(ch,1);
	}

 	else
 	{
 		p->freq++;
 	}  

 	//updates frequency in the tree
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
 	char s;

 	//initialise tree
 	node *root=new node('#',0);
 	while(cin>>s)
 	{
 		//pass to function root of tree and the character to add
 		dynamic(root,s);
 	}
 }