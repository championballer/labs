#include <bits/stdc++.h>

using namespace std;

vector<int> encryption(){
 string s;
cin>>s;
int N;
 map<string ,int>mapp;
cout<<"Number of Distinct characters: ";
cin>>N;
while(N--) {
string ch;
cin>>ch;
mapp.insert({ch,mapp.size()+1});
}
int index;
vector<int>v;
int i=0;
while(i<s.size()) {
string str="";
 index=0;
for(int j=i;j<s.size();j++)
{
 str+=s[j];
 map<string ,int>::iterator it= mapp.find(str);
 if(it!=mapp.end()) {
 index=it->second;
 i++;
 }
 else {
 mapp.insert({str,mapp.size()+1});
 v.push_back(index);
 break;
 }
}
}
v.push_back(index);
auto it=mapp.begin();
while(it!=mapp.end()) {
 cout<<it->first<<" "<<it->second<<endl;
 it++;
 }
for(int i=0;i<v.size();i++)
cout<<v[i]<<" ";
 return v;
}
int main(){
encryption();
}