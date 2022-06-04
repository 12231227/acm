#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1.5e6;
const int maxm = 1e5;
int tmps,val;
int l = 0;

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)
 
template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

int a[maxm + 11],c[maxm + 11][20],cnt[maxn + 11][20][2],son[maxm + 11],siz[maxm + 11];
ll sum[20];
vector <int> edge[maxm + 11];

void findson(int x,int fa) {
	siz[x] = 1;
	for (auto v : edge[x]) {
		if (v == fa) continue;
		findson(v , x);
		siz[x] += siz[v];
		if (siz[son[x]] < siz[v]) son[x] = v;
	} 
} 

void go(int x,int fa) {
	for (int i = 0; i <= l; i++)
		sum[i] += cnt[val ^ a[x]][i][c[x][i] ^ 1];
	for (auto v : edge[x]) {
		if (v == fa || v == tmps) continue;
		go(v , x);
	}
}

void calc(int x,int fa,int op) {
	for (int i = 0; i <= l; i++) cnt[a[x]][i][c[x][i]] += op;
	for (auto v : edge[x]) {
		if (v == fa || v == tmps) continue;
		calc(v , x , op);
	} 
} 

void dfs(int x,int fa,int op) { 
	for (auto v : edge[x]) { 
		if (v == fa || v == son[x]) continue;
		dfs(v , x , 0);
	} 
	if (son[x]) { dfs(son[x] , x , 1); tmps = son[x]; }
	val = a[x];
	for (int i = 0; i <= l; i++) cnt[a[x]][i][c[x][i]]++;
	for (auto v : edge[x]) { 
		if (v == fa || v == tmps) continue;
		go(v , x);
		calc(v , x , 1);
	} 
	tmps = 0;
	if (!op) calc(x , fa , -1);
} 

int main(){ 
	int n; read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++) { 
		int u,v; read(u); read(v);
		edge[u].pb(v);
		edge[v].pb(u);
	} 
	findson(1 , 0);
	ll ans = 0;
	for (int i = 0; (1 << i) <= n; i++) l = i;
	for (int j = 1; j <= n; j++)
		for (int i = 0; i <= l; i++)
			if (j & (1 << i)) c[j][i] = 1; else c[j][i] = 0;
	dfs(1 , 0 , 0);
	for (int i = 0; i <= l; i++) ans += sum[i] * (1 << i);
	printf("%lld\n" , ans);
} 
