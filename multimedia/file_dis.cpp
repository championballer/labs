#include <bits/stdc++.h>
using namespace std;
int main()
{
ofstream ofile;
string s;
cout << "Enter Data In File: ";
getline(cin, s);
ofile.open("ques1TextFile.txt");
ofile << s;
ofile.close();
ifstream infile;
infile.open("ques1TextFile.txt");
char t[100];
//char t[100];
if (infile.fail())
{
cout << "file not Present!!!" << endl;
return 0;
}
while (!infile.eof())
{
infile.getline(t, 100);
cout << t << endl;
}
infile.close();
return 0;
}