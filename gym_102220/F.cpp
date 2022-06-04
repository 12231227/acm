#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e5 + 20;
vector<int> edge[6 * maxn];
vector<int> reedge[6 * maxn];
int vis[6 * maxn];
int pt[6]; //0:A,1:B
int deg[6 * maxn];
int sg[6 * maxn];
int n;

void init()
{
	for (int i = 0; i <= n * 6 + 18; i++)
	{
		deg[i] = 0;
		sg[i] = -1;
		edge[i].clear();
		reedge[i].clear();
		vis[i] = 0;
	}
	return;
}

void addedge(int f, int b)
{
	for (int i = 0; i < 6; i++)
	{
		edge[6 * f + i].push_back(6 * b + (i + 1) % 6);
		deg[6 * f + i]++;
		reedge[6 * b + (i + 1) % 6].push_back(6 * f + i);
	}
}

void topsort()
{
	queue<int> q;
	for (int i = 6; i <= 6 * n + 5; i++)
	{
		if (deg[i] == 0)
		{
			sg[i] = pt[i % 6] ^ 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int nowpos = q.front();
		q.pop();
		if (sg[nowpos] == -1)
		{
			sg[nowpos] = pt[(nowpos) % 6] ^ 1;
			for (int v : edge[nowpos])
			{
				if (sg[v] == pt[(nowpos) % 6]) {
					sg[nowpos] = pt[(nowpos) % 6];
					break;
				}
			}
		}
		//bool nxt = (pt[nowpos % 6] == pt[(nowpos + 5) % 6]);
		bool wins = (sg[nowpos] == pt[(nowpos + 5) % 6]);
		for (int i : reedge[nowpos])
		{
			deg[i]--;
			if (wins && vis[i] == 0) {
				sg[i] = pt[(nowpos + 5) % 6];
				vis[i] = 1;
				q.push(i);
			}
			if (deg[i] == 0 && vis[i] == 0) {
				vis[i] = 1;
				q.push(i);
			}
		}
	}
}

char input1[10];
char input2[10];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			int f, b;
			cin >> f >> b;
			addedge(f, b);
		}
		cin >> input1;
		cin >> input2;
		for (int i = 0; i < 6; i++) {
			if (input1[i] == 'A')
				pt[i] = 0;
			else
				pt[i] = 1;
			if (input2[i] == '1')
				pt[i] ^= 1;
		}
		topsort();
		for (int i = 1; i <= n; i++ , puts("")) {
			for (int j = i * 6; j <= i * 6 + 5; j++) printf("%d" , sg[j]);
		}
//		for (int i = 1; i <= n; i++) {
//			if (sg[i * 6] == -1)
//				cout << "D";
//			if (sg[i * 6] == 0)
//				cout << "A";
//			if (sg[i * 6] == 1)
//				cout << "B";
//		}
//		cout << endl;
	}
	return 0;
} 
