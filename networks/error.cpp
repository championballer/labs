#include <bits/stdc++.h>
using namespace std;

void parity_check()
{
	string sender,receiver;
	cout<<"Data at sender: ";
	cin>>sender;

	///SENDER END
	///USING EVEN PARITY
	int count=0;
	for(int i=0;i<sender.size();i++)
		if(sender[i]=='1')
			count++;
	if(count%2==0)
		receiver=sender+'0';
	else
		receiver=sender+'1';

	cout<<"DATA TO TRANSMIT: "<<receiver<<endl;

	///RECEIVER SIDE
	cout<<"Data at receiver: ";
	cin>>receiver;
	count=0;
	for(int i=0;i<receiver.size();i++)
		if(receiver[i]=='1')
			count++;
	if(count%2==0)
	{		
		cout<<"ERROR FREE"<<endl;
		cout<<"DATA: ";
		for(int i=0;i<receiver.size()-1;i++)
			cout<<receiver[i];
		cout<<endl;
	}
	else
		cout<<"ERROR DETECTED"<<endl;
}

void CRC()
{
	string sender,receiver,divisor;
	cout<<"Data at sender: ";
	cin>>sender;
	cout<<"Divisor: ";
	cin>>divisor;
	
	///SENDER SIDE
	for(int i=0;i+1<divisor.size();i++)
		sender+='0';

	queue<char> CRC;
	int i;
	for(i=0;i<divisor.size();i++)
		CRC.push(sender[i]);
	for(;i<=sender.size();i++)
	{
		if(CRC.front()=='0')
		{
			CRC.pop();
			if(i!=sender.size())
				CRC.push(sender[i]);
			continue;
		}
		for(int j=0;j<divisor.size();j++)
		{
			if(CRC.front()==divisor[j])
				CRC.push('0');
			else
				CRC.push('1');
			CRC.pop();
		}
		CRC.pop();
		if(i!=sender.size())
			CRC.push(sender[i]);
	}
	for(int i=0;i<sender.size()-divisor.size()+1;i++)
		receiver+=sender[i];
	while(!CRC.empty())
	{
		receiver+=CRC.front();
		CRC.pop();
	}
	cout<<"Data to transmit: "<<receiver<<endl;
	
	///RECEIVER SIDE
	cout<<"Data received: ";
	cin>>receiver;

	sender=receiver;
	while(!CRC.empty())
		CRC.pop();
	for(i=0;i<divisor.size();i++)
		CRC.push(sender[i]);
	for(;i<=sender.size();i++)
	{
		if(CRC.front()=='0')
		{
			CRC.pop();
			if(i!=sender.size())
				CRC.push(sender[i]);
			continue;
		}
		for(int j=0;j<divisor.size();j++)
		{
			if(CRC.front()==divisor[j])
				CRC.push('0');
			else
				CRC.push('1');
			CRC.pop();
		}
		CRC.pop();
		if(i!=sender.size())
			CRC.push(sender[i]);
	}
	bool error=false;
	while(!CRC.empty())
	{
		if(CRC.front()=='1')
			error=true;
		CRC.pop();
	}
	if(error)
		cout<<"ERROR DETECTED"<<endl;
	else
		cout<<"ERROR FREE"<<endl;
}

pair<string,int> add_string(string A,string B)
{
	int carry=0;
	for(int j=B.size()-1;j>=0;j--)
	{
		int sum=B[j]-'0' + A[j] - '0' + carry;
		if(sum==0)
		{
			carry=0;
			A[j]='0';
		}
		else if(sum==1)
		{
			carry=0;
			A[j]='1';
		}
		else if(sum==2)
		{
			carry=1;
			A[j]='0';
		}
		else
		{
			carry=1;
			A[j]='1';
		}
	}
	return {A,carry};
}
void checksum()
{
	string sender,receiver;
	int K;
	cout<<"Data at sender: ";
	cin>>sender;
	cout<<"Value of each segment: ";
	cin>>K;

	///SENDER SIDE
	string checksum;
	int i;
	for(i=0;i<K;i++)
		checksum+=sender[i];
	for(;i<sender.size();)
	{
		string temp;
		for(int j=0;j<K;j++,i++)
			temp+=sender[i];
		
		pair<string,int> A=add_string(checksum,temp);
		checksum=A.first;
		if(A.second==1)
		{
			string temp;
			for(int i=0;i<K-1;i++)
				temp+='0';
			temp+='1';
			checksum=add_string(checksum,temp).first;
		}
	}
	for(int i=0;i<checksum.size();i++)
		if(checksum[i]=='0')
			checksum[i]='1';
		else
			checksum[i]='0';
	cout<<"DATA TO TRANSMIT: "<<sender+checksum<<endl;
	
	///RECEIVER SIDE
	cout<<"Data received: ";
	cin>>receiver;
	checksum.clear();
	for(i=0;i<K;i++)
		checksum+=receiver[i];
	for(;i<receiver.size();)
	{
		string temp;
		for(int j=0;j<K;j++,i++)
			temp+=receiver[i];
		
		pair<string,int> A=add_string(checksum,temp);
		checksum=A.first;
		if(A.second==1)
		{
			string temp;
			for(int i=0;i<K-1;i++)
				temp+='0';
			temp+='1';
			checksum=add_string(checksum,temp).first;
		}
	}
	for(int i=0;i<checksum.size();i++)
		if(checksum[i]=='0')
			checksum[i]='1';
		else
			checksum[i]='0';

	bool error=false;
	for(int i=0;i<checksum.size();i++)
		if(checksum[i]=='1')
			error=true;
	if(error)
		cout<<"ERROR DETECTED"<<endl;
	else
		cout<<"ERROR FREE"<<endl;
}

int func(int r)
{
	return ((1<<r)-r-1);
}
void hamming_code()
{
	string dataword;
	cout<<"Enter Dataword: ";
	cin>>dataword;
	int k=dataword.size();
	int r;
	
	///SENDER SIDE
	for(r=2;;r++)
		if(func(r)>=k)
			break;

	int m=k+r;
	bool arr[m+1],parity[m+1]={0};
	for(int i=1;i<=m;i*=2)
		parity[i]=true;
	for(int i=1,j=dataword.size()-1;i<=m;i++)
	{
		if(parity[i])
			continue;
		arr[i]=dataword[j]-'0';
		j--;
	}

	for(int i=1;i<=m;i++)
		if(parity[i])
		{
			int count=0;
			for(int j=i+1;j<=m;j++)
				if(!parity[j] && (j&i)!=0 && arr[j])
					count++;
			if(count%2==0)
				arr[i]=0;
			else
				arr[i]=1;
		}

	cout<<"Code Word: ";
	for(int i=m;i>=1;i--)
		cout<<arr[i];
	cout<<endl;

	///RECEIVER SIDE
	string receiver;
	cout<<"Enter Received data: ";
	cin>>receiver;
	for(int i=0,j=receiver.size()-1;i<j;i++,j--)
		swap(receiver[i],receiver[j]);
	m=receiver.size();
	int ans=0;
	for(int i=1;i<=m;i*=2)
	{
		int count=0;
		for(int j=i;j<=m;j++)
			if((j&i)!=0 && receiver[j-1]=='1')
				count++;
		if(count%2!=0)
			ans+=i;
	}
	if(ans==0)
		cout<<"No ERROR"<<endl;
	else
		cout<<ans<<" BIT is corrupted"<<endl;
}

int main()
{
	//parity_check();
	//CRC();
	//checksum();
	
	//hamming_code();
}