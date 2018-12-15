class buffer
{
	public:
	char * arr;
	int length;
	int size;

	buffer(int length)
	{
		this->length = length;
		size=0;
		arr = new char[1000];
		for(int i=0;i<length;i++)
		{
			arr[i] = '\0';
		}
	}

	void push_search(char to_push)
	{
		for(int i=length-1;i>0;i--)
		{
			arr[i] = arr[i-1];
		}
		arr[0] = to_push;
		if(size!=length)size++;
	}

	void push_la(char to_push)
	{
		if(size+1>length)
			exit(0);
		arr[size] = to_push;
		size++;

	}
	char pop()
	{
		
		char to_pop = arr[0];
		for(int i=0;i<size-1;i++)
		{
			arr[i] = arr[i+1];
		}
		size--;
		return to_pop;
	}

	vector<int> search(char current)
	{
		vector<int> result;
		for(int i=0;i<length;i++)
		{
			if(arr[i]==current)
			{
				result.push_back(i);
			}
		}

		return result;
	}

	void print()
	{
		for(int i=0;i<size;i++)cout<<arr[i]<<" ";
			cout<<endl;
	}


	~buffer()
	{
		delete arr;
	}


};

