#include <bits/stdc++.h>
using namespace std;

const int maxn = 4000000;

bool vis[maxn + 11] = {false};

double calc(double x1,double x2,double y1,double y2,double z1,double z2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

struct node{
	double a;
	int x,y;
}dis[maxn + 11];

struct point{
	int x,y,z;
}p[maxn + 11];

bool cmp(node x,node y) { return x.a < y.a; }
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			dis[++cnt].a = calc(p[i].x,p[j].x,p[i].y,p[j].y,p[i].z,p[j].z);
			dis[cnt].x = i;
			dis[cnt].y = j;
		}
	sort(dis + 1 , dis + 1 + cnt , cmp);
	for (int i = 1; i <= cnt; i++) {
		if (!vis[dis[i].x] && !vis[dis[i].y]) {
			vis[dis[i].x] = vis[dis[i].y] = true;
			printf("%d %d\n" , dis[i].x , dis[i].y);
		}
		
	}
}

