#include<bits/stdc++.h>

using namespace std;

void bitstuffing(string data)
{
	string flag = "01111110";
	string res = "";

	for(int i=0;i<data.length();i++)
	{
		bool check = true;
		for(int j=i;j<i+6;j++)
			if(data[j]!=flag[j-i])
				check = false;
		if(check==true)
        	{
            		for(int j=i;j<i+6;j++)
                	res = res + data[j];
            		i = i+5;
            		res = res + '0';
        	}
        	
		else res = res + data[i];
	}
		
	res = flag + res + flag;
	cout<<res<<endl;
}

void bytestuffing(string data)
{
	string flag = "01111110";
	string esc = "00011011";
	string res = "";
	for(int i=0;i+8<=data.length();i+=8)
	{
		bool check1 = true;
		for(int j=i;j<i+8;j++)
			if(data[j]!=flag[j-i])
				check1 = false;
		if(check1==true)
        	{
            		res = res + esc;
            		for(int j=i;j<i+8;j++)
                	res = res + data[j];
            		continue;
        	}
		bool check2 = true;
		for(int j=i;j<i+8;j++)
			if(data[j]!=esc[j-i])
				check2 = false;
		if(check2==true)
			res = res + esc;
		for(int j=i;j<i+8;j++)
			res = res + data[j];
	}
	res = flag + res + flag;
	cout<<res<<endl;
}

int main()
{
	string data;
	cout<<"Enter data: ";
	cin>>data;
	cout<<"Output after Bit stuffing: ";
	bitstuffing(data);
	cout<<"Output after Byte stuffing: ";
	bytestuffing(data);
	return 0;
}
