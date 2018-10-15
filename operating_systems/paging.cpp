#include<iostream>

using namespace std;

int main()
{
	int memsize=15;
	int pagesize, nofpage;
	int p[100];
	int frameno, offset;
	int logadd, phyadd;
	int i, choice=0;
	cout<<"Your memsize is "<<memsize<<endl;
	cout<<"Enter page size:";
	cin>>pagesize;

	nofpage=memsize/pagesize;

	for(i=0;i<nofpage;i++)
	{
	cout<<"Enter the frame of page"<<i+1<<":";
	cin>>p[i];
	}

	do
	{
		cout<<"Enter a logical address:";
		cin>>logadd;
		frameno=logadd/pagesize;
		offset=logadd%pagesize;
		phyadd=(p[frameno]*pagesize)+offset;
		cout<<"Physical address is: "<<phyadd<<endl;
		cout<<"Do you want to continue(1/0)?:";
		cin>>choice;
	}while(choice==1);

	return 1;
}

