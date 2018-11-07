#include<bits/stdc++.h>
using namespace std;

string to_string(int val)
{
    string ans = "";
    while(val!=0){
        int d = val%10;
        char temp = (char)(d+'0');
        ans = temp + ans;
        val/=10;
    }
    return ans;
}

string compress(string str)
{
    string compress_str = "";
    int i = 0;
    while(i<str.length())
    {
        int j = i, count = 0;
        while(j<str.length() && str[j]==str[i])
        {
            j++;
            count++;
        }
        if(count==1)
            compress_str += str[i];
        else
            compress_str += str[i]+to_string(count);
        i = j;
    }
    return compress_str;
}

string decompress(string str)
{
    string decompress_str = "";
    int i = 0;
    while(i<str.length())
    {
        char cc = str[i];
        i++;
        int num = 0;
        while(i<str.length() && str[i]>='0' && str[i]<='9')
        {
            num = num*10+(str[i]-'0');
            i++;
        }
        if(num==0)
            decompress_str += cc;
        else
            while(num-->0)
                decompress_str += cc;
    }
    return decompress_str;
}

int main()
{
    cout<<"Enter string to compress: ";
    string str;
    cin>>str;
    string compress_str = compress(str);
    cout<<"Compressed String: "<<compress_str<<endl;
    string decompress_str = decompress(compress_str);
    cout<<"Decompressed String: "<<decompress_str<<endl;
    return 0;
}