#include<bits/stdc++.h>
using namespace std;

void paritycheck(string orgnaldata)
{
    cout<<"**PARITY CHECK**"<<endl;

    cout<<"Sender"<<endl;
    string sent = orgnaldata;
    int num1s = 0;
    for(int i=0;i<sent.length();i++)
        if(sent[i]=='1')
            num1s++;
    if(num1s%2!=0)
    {
        cout<<"Parity bit is 1"<<endl;
        sent = sent + '1';
    }
    else
    {
        cout<<"Parity bit is 0"<<endl;
        sent = sent + '0';
    }
    cout<<"Sent data is: "<<sent<<endl;

    cout<<"Reciever"<<endl;
    string recieved;
    cout<<"Enter recieved data: ";
    cin>>recieved;
    int num1r = 0;
    for(int i=0;i<recieved.length();i++)
        if(recieved[i]=='1')
            num1r++;
    if(num1r%2!=0)
        cout<<"Data corrupted."<<endl;
    else
        cout<<"Data correct."<<endl;
}

void cyclicredundancycheck(string orgnaldata)
{
    cout<<"**CYCLIC REDUNDANCY CHECK**"<<endl;

    string divisor;
    cout<<"Enter divisor: ";
    cin>>divisor;

    cout<<"Sender"<<endl;
    string sent = orgnaldata;
    stack<char> stk;
    for(int i=0;i<divisor.length()-1;i++)
        sent = sent + '0';
    for(int i=sent.length()-1;i>=0;i--)
        stk.push(sent[i]);
    while(stk.size()>=divisor.length())
    {
        if(stk.top()=='0')
        {
            stk.pop();
            continue;
        }
        char arr[divisor.length()];
        for(int i=0;i<divisor.length();i++)
        {
            char cc = stk.top();
            stk.pop();
            if(cc==divisor[i])
                arr[i] = '0';
            else
                arr[i] = '1';
        }
        for(int i=divisor.length()-1;i>=1;i--)
            stk.push(arr[i]);
    }
    string crc = "";
    while(!stk.empty())
    {
        crc = crc + stk.top();
        stk.pop();
    }
    cout<<"CRC calculated is: "<<crc<<endl;
    sent = orgnaldata + crc;
    cout<<"Sent data is: "<<sent<<endl;

    cout<<"Reciever"<<endl;
    string recieved;
    cout<<"Enter recieved data: ";
    cin>>recieved;
    for(int i=sent.length()-1;i>=0;i--)
        stk.push(recieved[i]);
    while(stk.size()>=divisor.length())
    {
        if(stk.top()=='0')
        {
            stk.pop();
            continue;
        }
        char arr[divisor.length()];
        for(int i=0;i<divisor.length();i++)
        {
            char cc = stk.top();
            stk.pop();
            if(cc==divisor[i])
                arr[i] = '0';
            else
                arr[i] = '1';
        }
        for(int i=divisor.length()-1;i>=1;i--)
            stk.push(arr[i]);
    }
    bool flag = true;
    while(!stk.empty())
    {
        char cc = stk.top();
        stk.pop();
        if(cc!='0')
            flag = false;
    }
    if(flag==false)
        cout<<"Data corrupted."<<endl;
    else
        cout<<"Data correct."<<endl;
}

string add_string(int n,string A,string B)
{
	int carry = 0;
	string res = "";
	for(int i=n-1;i>=0;i--)
	{
		int sum = B[i]-'0' + A[i] - '0' + carry;
		if(sum==0)
		{
		    carry = 0;
			res = '0'+res;
		}
		else if(sum==1)
		{
		    carry = 0;
			res = '1'+res;
		}
		else if(sum==2)
		{
		    carry = 1;
			res = '0'+res;
		}
		else
		{
		    carry = 1;
			res = '1'+res;
		}
	}
	return res;
}

void checksum(string orgnaldata)
{
    cout<<"**CHECKSUM**"<<endl;

    int n;
    cout<<"Enter number of bits in a segment: ";
    cin>>n;
    if(orgnaldata.length()%n!=0)
    {
        cout<<"Value of n is incorrect.";
        return;
    }

    cout<<"Sender"<<endl;
    string sent = orgnaldata;
    string checksum = "";
    for(int i=0;i<n;i++)
        checksum += '0';
    int k = 0;
    while(k<sent.size())
    {
        string seg = "";
        for(int i=k;i<k+n;i++)
            seg += sent[i];
        k += n;
        checksum = add_string(n,checksum,seg);
    }
    for(int i=0;i<n;i++)
    {
        if(checksum[i]=='0')
            checksum[i] = '1';
        else
            checksum[i] = '0';
    }
    cout<<"Checksum: "<<checksum<<endl;
    sent = sent+checksum;
    cout<<"Sent data is: "<<sent<<endl;

    cout<<"Reciever"<<endl;
    string recieved;
    cout<<"Enter recieved data: ";
    cin>>recieved;
    string isvalid = "";
    for(int i=0;i<n;i++)
        isvalid += '0';
    k = 0;
    while(k<recieved.size())
    {
        string seg = "";
        for(int i=k;i<k+n;i++)
            seg += recieved[i];
        k += n;
        isvalid = add_string(n,isvalid,seg);
    }
    for(int i=0;i<n;i++)
    {
        if(isvalid[i]=='0')
            isvalid[i] = '1';
        else
            isvalid[i] = '0';
    }
    bool flag = true;
    for(int i=0;i<n;i++)
        if(isvalid[i]=='1')
            flag = false;
    if(flag==false)
        cout<<"Data corrupted."<<endl;
    else
        cout<<"Data correct."<<endl;
}

int main()
{
    string data;
    cout<<"Enter Data: ";
    cin>>data;
    //paritycheck(data);
    //cyclicredundancycheck(data);
    checksum(data);
    return 0;
}
