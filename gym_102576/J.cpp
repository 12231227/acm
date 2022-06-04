#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
using namespace std;

const int maxn = 1e6;
int fa[maxn + 11];
vector <int> lineyz[maxn + 11],linezy[maxn + 11],linezx[maxn + 11];
struct node{
	int x,y,num;
};
vector <node> X,Y;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int x,int y) {
	int fax = find(x);
	int fay = find(y);
	if (fax == fay) return;
	fa[fax] = fay;
}

void go(int u,vector <int> &v) {
	if (v.empty()) return;
	for (auto x : v) merge(u , x);
	int x = v.front();
	v.clear();
	v.pb(x);
}

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		map <pair <int,int> , int> mpx,mpy,mpz;
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= maxn; i++) lineyz[i].clear(),linezy[i].clear(),linezx[i].clear();
		X.clear(); Y.clear();
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) {
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			if (x == -1) {
				X.pb(node{y , z , i});
				mpx[mp(y , z)] = i;
				for (int j = 0; j < 4; j++){
					if (mpx.count(mp(y + dx[j] , z + dy[j]))) merge(i , mpx[mp(y + dx[j] , z + dy[j])]);
				}
			}
			else if (y == -1) {
				Y.pb(node{x , z , i});
				mpy[mp(x , z)] = i;
				for (int j = 0; j < 4; j++){ 
					if (mpy.count(mp(x + dx[j] , z + dy[j]))) merge(i , mpy[mp(x + dx[j] , z + dy[j])]);
				}
				lineyz[z].pb(i);
			}
			else {
				mpz[mp(x , y)] = i;
				for (int j = 0; j < 4; j++){
					if (mpz.count(mp(x + dx[j] , y + dy[j]))) merge(i , mpz[mp(x + dx[j] , y + dy[j])]);
				}
				linezy[y].pb(i);
				linezx[x].pb(i);
			}
		}
		for (auto pi : X) {
			go(pi.num , lineyz[pi.y - 1]);
			go(pi.num , lineyz[pi.y]);
			go(pi.num , lineyz[pi.y + 1]);
			go(pi.num , linezy[pi.x - 1]);
			go(pi.num , linezy[pi.x]);
			go(pi.num , linezy[pi.x + 1]);
		}
		for (auto pi : Y) {
			go(pi.num , linezx[pi.x - 1]);
			go(pi.num , linezx[pi.x]);
			go(pi.num , linezx[pi.x + 1]);
		}
		int q;
		scanf("%d",&q);
		auto get = [&](int x,int y,int z){
			if (mpx.count(mp(y , z))) return mpx[mp(y , z)];
			if (mpy.count(mp(x , z))) return mpy[mp(x , z)];
			if (mpz.count(mp(x , y))) return mpz[mp(x , y)];
			return 0;
		};
		while (q--) {
			int x1,y1,z1,x2,y2,z2;
			scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
			int n1 = get(x1 , y1 , z1);
			int n2 = get(x2 , y2 , z2);
			bool flag = false;
			if (n1 && n2 && find(n1) == find(n2)) flag = true;
			printf("%s\n" , flag ? "YES" : "NO");
		}
	} 
} 
