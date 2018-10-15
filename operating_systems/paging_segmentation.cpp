#include <bits/stdc++.h>
using namespace std;

void paging()
{
	int page_size,no_of_pages,no_of_frames;//frame size and page size will be same so only one required
	cout<<"Page Size, No of pages, No of frames: ";
	cin>>page_size>>no_of_pages>>no_of_frames;
	int d=0,temp=page_size-1;
	while(temp)
	{
		d++;
		temp/=2;
	}
	int p=0;
	temp=no_of_pages-1;
	while(temp)
	{
		p++;
		temp/=2;
	}
	int f=0;
	temp=no_of_frames-1;
	while(temp)
	{
		f++;
		temp/=2;
	}
	
	///OFFSET = d bits, Page number  = p bits, frame number = f bits;

	cout<<"ENTER PAGING OF PAGES"<<endl;
	int page_table[no_of_pages];
	for(int i=0;i<no_of_pages;i++)
		cin>>page_table[i];

	int T;
	cout<<"TEST CASES: ";
	cin>>T;
	while(T--)
	{
		string logical_address;
		cin>>logical_address;
		if(logical_address.size()!=p+d)
		{
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
			continue;
		}
		string page,offset;
		for(int i=0;i<p;i++)
			page+=logical_address[i];
		for(int i=p;i<logical_address.size();i++)
			offset+=logical_address[i];


		int pn=0,off=0;
		for(int i=page.size()-1,j=1;i>=0;i--,j*=2)
			pn+=((page[i]-'0')*j);
		for(int i=offset.size()-1,j=1;i>=0;i--,j*=2)
			off+=((offset[i]-'0')*j);
		int fn=page_table[pn];

		if(fn>=no_of_frames || pn>=no_of_pages || off>=page_size)
		{
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
			continue;
		}

		string frame;
		while(fn)
		{
			frame+=(fn%2)+'0';
			fn/=2;
		}
		while(frame.size()!=f)
			frame+='0';
		for(int i=0,j=frame.size()-1;i<j;i++,j--)
			swap(frame[i],frame[j]);
		string physical_address=frame;
		for(int i=p;i<logical_address.size();i++)
			physical_address+=logical_address[i];
		cout<<"PHYSICAL ADDRESS: "<<physical_address<<endl;
	}
}

void segmentation()
{
	int no_of_segments;
	cout<<"No of Segments: ";
	cin>>no_of_segments;
	cout<<"ENTER Limit, base for each segment"<<endl;
	pair<int,int> segment_table[no_of_segments];
	for(int i=0;i<no_of_segments;i++)
		cin>>segment_table[i].first>>segment_table[i].second;
	int s=0,temp=no_of_segments-1;
	while(temp)
	{
		s++;
		temp/=2;
	}

	int T;
	cout<<"TEST CASES: ";
	cin>>T;
	while(T--)
	{
		string logical_address;
		cout<<"LOGICAL ADDRESS: ";
		cin>>logical_address;
		string segment,offset;
		for(int i=0;i<s;i++)
			segment+=logical_address[i];
		for(int i=s;i<logical_address.size();i++)
			offset+=logical_address[i];
		int off=0,seg=0;
		for(int i=offset.size()-1,j=1;i>=0;i--,j*=2)
			off+=((offset[i]-'0')*j);
		for(int i=segment.size()-1,j=1;i>=0;i--,j*=2)
			seg+=((segment[i]-'0')*j);
	
		if(seg>=no_of_segments || off>=segment_table[seg].first)
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
		else
		{
			string add;
			int base=segment_table[seg].second;
			while(base)
			{
				add+=base%2+'0';
				base/=2;
			}
			for(int i=0,j=add.size()-1;i<j;i++,j--)
				swap(add[i],add[j]);
			string physical_address=add;
			physical_address+=offset;
			cout<<"PHYSICAL ADDRESS: "<<physical_address<<endl;
		}
	}
}

void two_level_paging()
{
	int outer_pages,outer_frames,inner_pages,inner_frames,size;
	cout<<"No of outer_pages, No of outer frames, No of inner_pages, No of inner frames, Page_size: ";
	cin>>outer_pages>>outer_frames>>inner_pages>>inner_frames>>size;
	int p1=0,p2=0,d=0,f=0;
	int temp=outer_pages-1;
	while(temp)
	{
		p1++;
		temp/=2;
	}
	temp=inner_pages-1;
	while(temp)
	{
		p2++;
		temp/=2;
	}
	temp=size-1;
	while(temp)
	{
		d++;
		temp/=2;
	}
	temp=inner_frames-1;
	while(temp)
	{
		f++;
		temp/=2;
	}

	int outer_table[outer_pages],inner_table[outer_frames][inner_pages];
	cout<<"Outer Page Table: "<<endl;
	for(int i=0;i<outer_pages;i++)
		cin>>outer_table[i];

	cout<<"Inner Page Table: "<<endl;
	for(int i=0;i<outer_frames;i++)
		for(int j=0;j<inner_pages;j++)
			cin>>inner_table[i][j];

	int T;
	cout<<"TEST CASES: ";
	cin>>T;
	while(T--)
	{
		string logical_address;
		cin>>logical_address;
		string p1s,p2s,off;
		if(logical_address.size()!=(p1+p2+d))
		{
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
			continue;
		}
		for(int i=0;i<p1;i++)
			p1s+=logical_address[i];
		for(int i=p1;i<p1+p2;i++)
			p2s+=logical_address[i];
		for(int i=p1+p2;i<p1+p2+d;i++)
			off+=logical_address[i];

		int p1_no=0,p2_no=0,d_no=0;
		for(int i=p1s.size()-1,j=1;i>=0;i--,j*=2)
			p1_no+=((p1s[i]-'0')*j);
		for(int i=p2s.size()-1,j=1;i>=0;i--,j*=2)
			p2_no+=((p2s[i]-'0')*j);
		for(int i=off.size()-1,j=1;i>=0;i--,j*=2)
			d_no+=((off[i]-'0')*j);

		if(d_no>=size || p1_no>=outer_pages || p2_no>=inner_pages)
		{
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
			continue;
		}

		int f_no=inner_table[outer_table[p1_no]][p2_no];
		if(f_no>=inner_frames)
		{
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
			continue;
		}
		string frame;
		while(f_no)
		{
			frame+=f_no%2+'0';
			f_no/=2;
		}
		while(frame.size()<f)
			frame+='0';
		for(int i=0,j=frame.size()-1;i<j;i++,j--)
			swap(frame[i],frame[j]);
		string physical_address=frame;
		physical_address+=off;
		cout<<"PHYSICAL ADDRESS: "<<physical_address<<endl;
	}
}

void inverted_paging()
{
	int process,page_size,no_of_pages,no_of_frames;
	cout<<"No of processes, Page Size, No of pages, No of frames: ";
	cin>>process>>page_size>>no_of_pages>>no_of_frames;
	int d=0,temp=page_size-1;
	while(temp)
	{
		d++;
		temp/=2;
	}
	int p=0;
	temp=no_of_pages-1;
	while(temp)
	{
		p++;
		temp/=2;
	}
	int f=0;
	temp=no_of_frames-1;
	while(temp)
	{
		f++;
		temp/=2;
	}
	int pid=0;
	temp=process-1;
	while(temp)
	{
		pid++;
		temp/=2;
	}
	
	///OFFSET = d bits, Page number  = p bits, frame number = f bits;

	cout<<"ENTER PAGE TO ith FRAME: "<<endl;
	pair<int,int> frame_table[no_of_frames];
	for(int i=0;i<no_of_frames;i++)
		cin>>frame_table[i].first>>frame_table[i].second;

	int T;
	cout<<"TEST CASES: ";
	cin>>T;
	while(T--)
	{
		string logical_address;
		cin>>logical_address;
		if(logical_address.size()!=pid+p+d)
		{
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
			continue;
		}
		string page,offset,processs;
		for(int i=0;i<pid;i++)
			processs+=logical_address[i];
		for(int i=pid;i<p+pid;i++)
			page+=logical_address[i];
		for(int i=p+pid;i<logical_address.size();i++)
			offset+=logical_address[i];

		int pn=0,off=0,process_no=0;
		for(int i=page.size()-1,j=1;i>=0;i--,j*=2)
			pn+=((page[i]-'0')*j);
		for(int i=offset.size()-1,j=1;i>=0;i--,j*=2)
			off+=((offset[i]-'0')*j);
		for(int i=processs.size()-1,j=1;i>=0;i--,j*=2)
			process_no+=((processs[i]-'0')*j);
		
		int fn=-1;
		for(int i=0;i<no_of_frames;i++)
			if(frame_table[i]==make_pair(process_no,pn))
			{
				fn=i;
				break;
			}

		if(fn==-1 || process_no>=process || pn>=no_of_pages || off>=page_size)
		{
			cout<<"ILLEGAL LOGICAL ADDRESS"<<endl;
			continue;
		}

		string frame;
		while(fn)
		{
			frame+=(fn%2)+'0';
			fn/=2;
		}
		while(frame.size()!=f)
			frame+='0';
		for(int i=0,j=frame.size()-1;i<j;i++,j--)
			swap(frame[i],frame[j]);
		string physical_address=frame;
		for(int i=p+pid;i<logical_address.size();i++)
			physical_address+=logical_address[i];
		cout<<"PHYSICAL ADDRESS: "<<physical_address<<endl;
	}
}

int main()
{
	//paging();
	//segmentation();
	//two_level_paging();
	//inverted_paging();
}
