#include<iostream>
#include<vector>

int avg(const int & x,const int & y,const int & z)
{
	return (x+y+z)/3;
}

int main()
{
	int la, ua;
	std::cout<<"Enter valid range of A:";
	std::cin>>la>>ua;

	int lb, ub;
	std::cout<<"Enter valid range of B:";
	std::cin>>lb>>ub;

	int lc, uc;
	std::cout<<"Enter valid range of C:";
	std::cin>>lc>>uc;

	int nt = 4*3+1;
	std::cout<<"Total number of test cases:"<<nt<<std::endl;


	int lap = la+1;
	int uam = ua-1;
	int noma = (la+ua)/2;
	int lbp = lb+1;
	int ubm = ub-1;
	int nomb = (lb+ub)/2;
	int lcp = lc+1;
	int ucm = uc-1;
	int nomc = (lc+uc)/2;

	std::vector<int> va{la,lap,noma,uam,ua};
	std::vector<int> vb{lb,lbp,nomb,ubm,ub};
	std::vector<int> vc{lc,lcp,nomc,ucm,uc};

	std::cout<<"A    B    C    Expected Ouput"<<std::endl;
	int j=0;
	int count = 0;
	for(int i=0;i<15;i++)
	{
		if(j==0)
		{
			std::cout<<va[count]<<"   "<<nomb<<"   "<<nomc<<"   "<<avg(va[count],nomb,nomc)<<std::endl;
			count++;

			if(count==5)
			{
				j+=1;
				count = 0;
			}
		}

		else if(j==1)
		{
			if(count!=2)
			std::cout<<noma<<"   "<<vb[count]<<"   "<<nomc<<"   "<<avg(noma,vb[count],nomc)<<std::endl;
			count++;

			if(count==5)
			{
				j+=1;
				count = 0;
			}
		}	

		else
		{
			if(count!=2)
			std::cout<<noma<<"   "<<nomb<<"   "<<vb[count]<<"   "<<avg(noma,nomb,vb[count])<<std::endl;
			count++;

			if(count==5)
			{
				j+=1;
				count = 0;
			}
		}
	}
}