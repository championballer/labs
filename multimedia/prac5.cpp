#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 char c;
 double cummulative = 0.0, freq;
 cout << "How many characters are there\n";
 cin >> n;
 cout << "Enter char and its probability in alphabetical order\n";
 double range_from[256], range_to[256];
 memset(range_from, 0, sizeof range_from);
 memset(range_to, 0, sizeof range_to);
 for (int i = 0; i < n; i++)
 {
 cin >> c;
 cin >> freq;
 range_from[c] = cummulative;
 cummulative += freq;
 range_to[c] = cummulative;
 cout << range_from[c] << " - " << range_to[c] << endl;
 }
 string str;
 cout << "Enter string to be encoded" << endl;
 cin >> str;
 cout << endl;
 double low = 0.0, high = 1.0, diff = 1.0;
 n = str.length();
 for (int i = 0; i < n; i++)
 {
 high = low + (diff * range_to[str[i]]);
 low = low + (diff * range_from[str[i]]);
 diff = high - low;
 }
 double encoded = (low + high) / 2.0;
 cout << "Encoded string is " << encoded << endl;
 cout << "Decoded string is ";
 while (n--)
 {
 for (int i = 0; i < 256; i++) {
 if (encoded >= range_from[i] && encoded < range_to[i])
 {
 c = i;
 break;
 }
 }
 cout << c;
 encoded = (encoded - range_from[c]) / (range_to[c] -
range_from[c]);
 }
 return 0;
}