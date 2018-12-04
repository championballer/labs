#include <bits/stdc++.h>
using namespace std;

struct Node
{
 	char ch;
 	int freq;
 	Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right)
{
 	Node *node = new Node();
 	node->ch = ch;
 	node->freq = freq;
 	node->left = left;
 	node->right = right;
 	return node;
}

struct comp
{
 	bool operator()(Node *l, Node *r)
 	{
 		return l->freq > r->freq;
 	}	
};

void encode(Node *root, string str, unordered_map<char, string>&huffmanCode)
{
 	if(root == NULL)
 		return;
 	if(!root->left && !root->right)
 		huffmanCode[root->ch] = str;
 	encode(root->left, str + "0", huffmanCode);
 	encode(root->right, str + "1", huffmanCode);
}

void decode(Node *root, int &index, string str)
{
 	if(root == NULL)
 		return;
 	if(!root->left && !root->right)
 	{
 		cout << root->ch;
 		return;
 	}
 	
 	index += 1;
 	if (str[index] == '0')
 		decode(root->left, index, str);
 	else
 		decode(root->right, index, str);
}

void buildHuffmanTree(string text)
{
 	unordered_map<char, int> freq;
 	for (char ch : text)
 	{
 		freq[ch] += 1;
 	}
 		
 	priority_queue<Node *, vector<Node *>, comp> pq;
 	for (auto pair : freq)
 	{
 		pq.push(getNode(pair.first, pair.second, NULL, NULL));
 	}
 	
 	while (pq.size() != 1)
 	{
 		Node *left = pq.top();
 		pq.pop();
 		Node *right = pq.top();
 		pq.pop();
 		int sum = left->freq + right->freq;
 		pq.push(getNode('\0', sum, left, right));
 	}
 	
 	Node *root = pq.top();
 	unordered_map<char, string> huffmanCode;
 	encode(root, "", huffmanCode);
 	cout << "Hufffman Codes are:\n\n";
 	for (auto pair : huffmanCode)
 	{
 		cout << pair.first << " " << pair.second << endl;
 	}

 	cout << "\nOriginal String was: " << text << "\n";
 	string str = "";
 	for (char ch : text)
 	{
 		str += huffmanCode[ch];
 	}
 	
 	cout << "\nEncoded String is: " << str << endl;
 	int index = -1;
 	cout << "Decoded string is: ";
 	while (index < (int)str.size() - 2)
 	{
 		decode(root, index, str);
 	}
 	cout << endl;
}

int main()
{
 	string s;
 	cin >> s;
 	buildHuffmanTree(s);
 	return 0;
}