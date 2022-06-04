#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;

int m,n,k,t;
vector <pair<int,int> > pos[maxn + 11];
int a[maxn + 11];

bool cmp(int a,int b) { return a > b; }

bool check(int val) {
	int to = 0;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		now++;
		if (pos[i].empty()) {
			to = max(to , i);
			continue;
		}
		int rig = to;
		for (int j = 0; j < pos[i].size(); j++) {
			int dis = pos[i][j].first;
			int v = pos[i][j].second;
			if (rig >= dis || val >= v) continue;
			rig = dis;
		}
		now += 2 * (rig - to);
		to = max(rig , i);
		if (now >= t) return false;
	}
	return now + 1 <= t;
} 

int main(){
	scanf("%d %d %d %d",&m,&n,&k,&t);
	for (int i = 1; i <= m; i++) scanf("%d",&a[i]);
	sort(a + 1 , a + 1 + m , cmp);
	for (int i = 1; i <= k; i++) {
		int x;
		scanf("%d",&x);
		pair <int,int> pi;
		scanf("%d %d",&pi.first,&pi.second);
		pos[x].push_back(pi);
	} 
	int ans = 0;
	int l = 1; int r = m;
	while (l <= r) { 
		int mid = (l + r) / 2;
		if (check(a[mid])) { ans = mid; l = mid + 1; } 
		else r = mid - 1;
	} 
	printf("%d\n" , ans);
} 

