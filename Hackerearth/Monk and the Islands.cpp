#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, a, n) for (int i = a; i < n; i++)
#define fre(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define mem(name, value) memset(name, value, sizeof(name))
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define case cout << "Case " << t++ << ": ";

vector<int> adjlist[1001];
map<int, int> dis;

void bfs(int node, int d)
{
	queue<int> q;
	for (int i = 1; i <= 1001; i++)
	{
		dis[i] = INT_MAX;
	}
	q.push(node);
	dis[node] = d;
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		for (int it : adjlist[f])
		{
			if (dis[it] == INT_MAX)
			{
				q.push(it);
				dis[it] = dis[f] + 1;
			}
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 int t;
 cin>>t;
 while(t--)
 {
	int n,m;
	cin >> n>>m;
	for(int i=0 ;i<n;i++)
	{
	    adjlist[i].clear();
		dis.clear();
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	bfs(1, 0);
	cout<<dis[n]<<endl;
 }	
}
