#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 10000;
int low[maxn], dfn[maxn], head[maxn];
int n, m, tot, k, root;
bool flag[maxn];
vector<pair<int, int> > bridge;
struct Node
{
	int next, v;
}edge[maxn];

void Add_edge(int x, int y)
{
	edge[k].v = y; edge[k].next = head[x]; head[x] = k++;
	edge[k].v = x; edge[k].next = head[y]; head[y] = k++;
}

void Tarjan(int x, int father)
{
	int child = 0;
	dfn[x] = low[x] = ++tot;
	for (int i = head[x]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (!dfn[v])
		{
			child++;
			Tarjan(v, x);
			low[x] = min(low[x], low[v]);
			if (x != root && dfn[x] <= low[v]) flag[x] = 1;    //表示当前节点为割点
			if (x == root  && child == 2) flag[x] = 1;
			if (low[v] > dfn[x]) bridge.push_back(make_pair(x, v));
		}
		else if (v != father)
			low[x] = min(dfn[v], low[x]);
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	int x, y,num=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin>>x>>y;
		Add_edge(x, y);
	}
	root = 1;         
	Tarjan(1, root);
	cout << "图中割点个数为" << endl;;
	for (int i = 1, j = 0; i <= n; i++, j++) {
		if (flag[i]) {
			num++;
		}
	}
	cout << num << endl;
	cout << endl;
	system("pause");
	return 0;
}

