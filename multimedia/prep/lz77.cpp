/*
LZ77 Dynamic Dictionary Method
*/

#include<bits/stdc++.h>
using namespace std;
#include "buffer_class.h"

struct code
{
	int offset;
	int length;
	char key;
};

struct sub_code
{
	int length;
	char key;
};

sub_code calc(buffer & search_buffer, buffer & look_ahead,int index,char & current)
{	
	sub_code result;
	int length = 0;
	int i = index;
	int j=0;
	//search with look ahead buffer first
	for(;j<look_ahead.size;j++)
	{
		if(look_ahead.arr[j]==search_buffer.arr[i])
		{
			length++;
			i--;
		}

		else
		{
			result.length = length;
			result.key = look_ahead.arr[j];
			return result;	
		}
	}

	cin>>current;
	look_ahead.push_la(current);

	for(;i>=0 && look_ahead.arr[look_ahead.size-1]==search_buffer.arr[i];i--)
	{
		length++;
		cin>>current;
		look_ahead.push_la(current);
	}


	if(i<0)
	{
		for(int j=0;current==look_ahead.arr[j];j++)
		{
			length++;
			look_ahead.push_la(current);
			cin>>current;
		}
	}

	result.length = length;
	result.key = current;
	return result;
	
}

void print(vector<code> output)
{
	for(int i=0;i<output.size();i++)
	{
		cout<<"<"<<output[i].offset<<","<<output[i].length<<",c("<<output[i].key<<")>"<<endl;
	}
	cout<<endl;
}

//cabracadabrarrarrad

int main()
{
	int ws,lab,sb;
	cout<<"Please enter the size of window:";
	cin>>ws;
	cout<<"Please enter size of search_buffer";
	cin>>sb;
	lab = ws - sb;

	buffer search_buffer(sb);
	buffer look_ahead(lab);
	vector<code> output;
	char current;
	
	while(cin>>current)
	{	
		code ans;
		ans.offset = 0;
		ans.length = 0;
		ans.key = current;
		vector<int> indices = search_buffer.search(current);
		look_ahead.push_la(current);
		for(int i=0;i<indices.size();i++)
		{
			sub_code s_ans = calc(search_buffer,look_ahead,indices[i],current);	
			if(s_ans.length>ans.length)
			{
				ans.offset = indices[i];
				ans.length = s_ans.length;
				ans.key = s_ans.key;
			}
		}

		for(int i=0;look_ahead.size>0;)
		{
			search_buffer.push_search(look_ahead.pop());
		}

		
		output.push_back(ans);
		
	}
	
	print(output);
	//decode output

	string decoded = "";
	for(int i=0;i<output.size();i++)
	{
		code current = output[i];
		int offset = current.offset;
		int length = current.length;
		char key = current.key;
		cout<<"offset:"<<offset<<" "<<"length:"<<length<<" "<<"key:"<<key<<endl;
		for(int i=decoded.length()-offset-1,j=0;j<length;i++,j++)
		{
			cout<<decoded<<endl;
			cout<<i<<endl;
			cout<<decoded[i]<<endl;
			decoded+=decoded[i];
		}
		decoded+=key;
	}
	cout<<decoded<<endl;
}