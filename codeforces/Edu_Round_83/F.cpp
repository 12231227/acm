#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;
int to[maxn + 11][5];
int SG[maxn + 11];

struct game{
	int x,y,z;
	int sg[1000][4];
	game() {};
	game(int _x,int _y,int _z) {
		memset(sg , -1 , sizeof(sg));
		x = _x; y = _y; z = _z;
	}
	int mex(vector <int> v) {
		bool vis[3];
		for (int i = 0; i < 3; i++) vis[i] = false;
		for (auto x : v) vis[x] = true;
		for (int i = 0; i < 3; i++) if (!vis[i]) return i;
		return 3;
	}
	int get(int s,int p) {
		if (s <= 0) return sg[0][p] = 0;
		if (sg[s][p] != -1) return sg[s][p];
		if (p == 0) return sg[s][p] = mex({get(s - x , 0) , get(s - y , 1) , get(s - z , 2)});
		if (p == 1) return sg[s][p] = mex({get(s - x , 0) , get(s - z , 2)});
		if (p == 2) return sg[s][p] = mex({get(s - x , 0) , get(s - y , 1)});
	} 
}g;

int s[5],l[5];
int a[3][111];

pair<int,int> find(int id){
	for (int i = 1; i < 100; i++)
		for (int j = 1; i + 2 * j - 1 <= 100; j++) {
			bool flag = true;
			//i - i + j - 1
			for (int k = 1; i + (k + 1) * j - 1 <= 100; k++){
				if (!flag) break;
				for (int l = 1; l <= j; l++)
					if (a[id][i + l - 1] != a[id][i + k * j + l - 1]) { flag = false; break; }
			}
			if (flag) return make_pair(i , j);
		}
} 

int query(long long x,int id) {
	if (x <= 0) return 0;
	if (x <= 100) return a[id][x];
	return a[id][s[id] + (x - s[id]) % l[id]];
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,x,y,z;
		scanf("%d %d %d %d",&n,&x,&y,&z);
		g = game(x , y , z);
		for (int i = 1; i <= 100; i++)
			a[0][i] = g.get(i , 0);
		pair <int,int> pi = find(0); s[0] = pi.first; l[0] = pi.second;
		for (int i = 1; i <= 100; i++) a[1][i] = g.get(i , 1);
		pi = find(1); s[1] = pi.first; l[1] = pi.second;
		for (int i = 1; i <= 100; i++) a[2][i] = g.get(i , 2);
		pi = find(2); s[2] = pi.first; l[2] = pi.second;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			long long val;
			scanf("%lld",&val);
			SG[i] = query(val , 0);
			to[i][0] = query(val - x , 0); to[i][1] = query(val - y , 1); to[i][2] = query(val - z , 2);
			sum ^= SG[i];
		} 
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int tmp = sum ^ SG[i];
			for (int j = 0; j < 3; j++)
				if (to[i][j] == tmp) ans++;
		}
		printf("%d\n" , ans);
	} 
} 

