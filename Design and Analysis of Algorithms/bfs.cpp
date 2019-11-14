#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> > &a, int s)
{
	int n = a.size();
	vector<bool> vis(n, false);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			if (!vis[a[x][i]])
			{
				q.push(a[x][i]);
				vis[a[x][i]] = true;
			}
		}
		cout << x + 1 << " ";
	}
}

int main()
{
	int n, e;
	cout<<"Please enter the number of nodes and edges:";
	cin >> n>>e;

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
	bfs(a, s - 1);
	cout << endl;
	return 0;
}
