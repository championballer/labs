#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("sample.txt");

	if(!inFile)
	{
		cerr<<"Unable to open file";
		exit(1);
	}

	string input[2];
	char x;
	int i=0;
	string STRING;
	/*while(inFile>>x)
	{
		if(x==' ')
			i++;
		input[i]+=x;

	}*/

	 /*while(!inFile.eof()) // To get you all the lines.
        {
	        getline(inFile,STRING); // Saves the line in STRING.
	        cout<<STRING; // Prints our STRING.
        }*/

    string line = "";
    while ( getline (inFile,line) )
    {
      cout << line << '\n';
    }

	cout<<input[0]<<" "<<input[1]<<endl;

	inFile.close();
}