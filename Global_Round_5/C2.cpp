#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4;
bool vis[maxn + 11] = {false};

struct point{
	int x,z,y;
	int num;
}p[maxn + 11];

bool cmp(point a,point b) {
	if (a.z != b.z) return a.z < b.z;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
		p[i].num = i;
	}
	sort(p + 1 , p + 1 + n , cmp);
	int i = 1;
	while (i <= n) {
		int r = i;
		while (r < n && p[r + 1].z == p[i].z) r++;
		if (i == r) { i++; continue; }
		int res = r - i + 1;
		for (int l = i; l < r;) {
			if (p[l].x == p[l + 1].x) { 
				printf("%d %d\n" , p[l].num,p[l + 1].num);
				vis[p[l].num] = vis[p[l + 1].num] = true;
				res -= 2;
				l += 2;
			}
			else l++;
		}
		int c = 0;
		for (int l = i; l <= r; l++) {
			if (res == 0) break;
			if (res == 1 && c % 2 == 0) break;
			if (vis[p[l].num]) continue;
			printf("%d%s",p[l].num , c % 2 == 0 ? " " : "\n");
			vis[p[l].num] = true; res--;
			c++;
		}
		i = r + 1;
	}
	int c = 0;
	for (int l = 1;l <= n; l++) {
		if (vis[p[l].num]) continue;
		printf("%d%s",p[l].num , c % 2 == 0 ? " " : "\n");
		vis[p[l].num] = true;
		c++;
	} 
} 

