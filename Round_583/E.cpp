#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000;

bool cmp(pair<int,int> a,pair<int,int> b){ return a.first > b.first; }

pair <int,int> node[2 * maxn + 11];
int pos[2 * maxn + 11],edge[2 * maxn + 11];

int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&node[i].first);
		node[i].second = i;
		pos[i] = 2 * i - 1;
	}
	sort(node + 1, node + 1 + n , cmp);
	int len = n;
	for (int i = 1; i <= n; i++) {
		int d = node[i].first;
		edge[i] = pos[i + d - 1];
		if (i + d - 1 == len) { len++; pos[len] = 2 * i; }
	}
	for (int i = 1; i < n; i++) printf("%d %d\n" , node[i].second * 2 - 1, node[i + 1].second * 2 - 1);
	for (int i = 1; i <= n; i++)
	 printf("%d %d\n",node[i].second * 2, edge[i] % 2 == 0 ? node[edge[i] / 2].second * 2 : node[(edge[i] + 1) / 2].second * 2 - 1);
} 

