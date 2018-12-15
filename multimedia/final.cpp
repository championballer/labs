/*
Dynamic Huffman Final Practical
*/

#include<bits/stdc++.h>
using namespace std;
#include"node.h"
	
struct node
{
 	int freq;
 	char data;
 	node *left,*right;
};

node *newnode(char data,int freq)
{
 	node *p=new node;
 	p->data=data;
 	p->freq = freq;
 	p->left=p->right=NULL;
 	return p;
}

int main()
{
	cout<<"Enter the running stream of characters"<<endl;
	char ch,s;

	node * root = 
}
