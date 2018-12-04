#include <bits/stdc++.h>
using namespace std;

string encode(string s)
{
 	string ans = "";
 	for (int i = 0; i < s.length(); i++)
 	{
 		int c = 1;
 		while (i < s.length() - 1 && s[i + 1] == s[i])
 		{
 			c += 1;
 			i++;
 		}
 		ans += s[i];
 		ans += to_string(c);
 	}
 	return ans;
}

string decode(string s)
{
 	string ans = "";
 	for (int i = 0; i < s.length(); i += 2)
 	for (int j = 0; j < s[i + 1] - 48; j++)
 	ans += s[i];
 	return ans;
}

int main()
{
 	string s;
 	cout << "Enter the string to be encoded :";
 	cin >> s;
	string encoded = encode(s);
 	cout << "Encoded String for \"" << s << "\" is :" << encoded <<endl;
 	string decoded = decode(encoded);
 	cout << "Decoded String for \"" << encoded << "\" is :" << decoded<< endl;
 	return 0;
}