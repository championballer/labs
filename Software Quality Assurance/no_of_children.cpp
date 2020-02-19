#include<bits/stdc++.h>

using namespace std;

map<string,int> child_freq;

class A{

	string parent;
	public:

	A()
	{
		parent = "";
	}

	void parentFreqIncrement()
	{
		//cout<<"Entered parent Freq Increment function"<<endl;
		if(child_freq.find(this->parent)==child_freq.end())
		{
			child_freq[this->parent]=1;
		}

		else child_freq[this->parent]++;
	}
};

class B : public A{

	string parent;
public:

	B()
	{
		parent = "A";
		parentFreqIncrement();
	}
};

class C : public A{
	
	string parent;

public:

	C()
	{
		parent = "A";
		parentFreqIncrement();
	}

};

class D : public B{

	string parent;

public:

	D()
	{
		parent = "B";
		parentFreqIncrement();
	}
};

class E : public C{

	string parent;

public:

	E()
	{
		parent = "C";
		parentFreqIncrement();
	}
};

int main()
{
	A sample;
	B * sampleChild = new B();
	B * sampleChild2 = new B();
	C * sampleChild3 = new C();
	D * sampleChild4 = new D();
	D * sampleChild5 = new D();
	E * sampleChild6 = new E();
	for(auto it = child_freq.begin();it!=child_freq.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}