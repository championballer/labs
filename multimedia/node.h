class node
{
	public:
	int freq;
	char data;
	node * left;
	node* right;

	node(char data, int freq)
	{
		this->data = data;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
};