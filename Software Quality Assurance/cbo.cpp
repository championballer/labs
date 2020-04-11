#include<bits/stdc++.h> 

using namespace std;

class sample1{
	public :
		int a;
		int b;
		int c;
		static int ua;
		
		sample1()
		{ 
			a=0;
			b=0; 
			c=0;
		}

		static void incua(int uinc)
		{
			ua+=uinc;
		}

		static int retua()
		{ 
			return ua;
		}
};

class sample2{ 
	public :
		int x;
		int y;
		int z;
		static int ub; 

		sample2()
		{
			x=10;
			y=10; 
			z=10;
		}

		static void incub(int uinc)
		{
			ub+=uinc;
		}

		static int retub()
		{ 
			return ub;
		} 
};

class sample3{ 
		public :
			int p;
			int q;
			int r;
			static int uc; 

			sample3()
			{
				uc=0;
				sample1 s1; 
				sample2 s2; 
				sample1::incua(1); 
				sample2::incub(1); 
				uc+=2; 
				p=s1.a+s2.x; 
				q=s1.b+s2.y; 
				r=s1.c+s2.z;
			}

			static int retuc()
			{
				return uc; 
			}

};

int sample1::ua=0; 
int sample2::ub=0; 
int sample3::uc=0; 

int main(){
	sample1 s1;
	sample2 s2;
	sample3 s3;
	cout<<"CBO of class sample1 = "<<s1.retua()<<endl; cout<<"CBO of class sample2 = "<<s2.retub()<<endl;

	cout<<"CBO of class sample3 = "<<s3.retuc()<<endl; 
}