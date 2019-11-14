#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> > &a, int s, vector<bool> &vis)
{
	vis[s] = true;
	cout << s + 1 << " ";
	for (int i = 0; i < a[s].size(); i++)
	if (!vis[a[s][i]])
	dfs(a, a[s][i], vis);
}

int main()
{
	int n, e;
	cout<<"Please enter the number of nodes and edges:";
	cin >> n >>e;

	cout<<"Please enter source, destination for each edge:";
	vector<vector<int> > a(n, vector<int>(1, 0));
	for (int i = 0; i < e; i++)
	{
		int x, y;

		cin >> x >> y;
		a[x - 1].push_back(y - 1);
		a[y - 1].push_back(x - 1);
	}
	int s;
	cout << "Enter the source node: ";
	cin >> s;
	vector<bool> vis(n, false);
	dfs(a, s - 1, vis);
	cout << endl;
	return 0;
}
