#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;
const int maxn = 2500;
ll add(ll a,ll b) { a += b; if (a >= mol) a -= mol; return a; }
ll sub(ll a,ll b) { a -= b; if (a < 0) a += mol; return a; }

ll val[maxn + 11],pre[maxn + 11],len[maxn + 11],vp[maxn + 11];
pair<ll,ll> c[maxn + 11];
char ch[maxn + 11];
int op[maxn + 11];

ll get(int id,ll r) {
	if (id == 0) return pre[r];
	if (r <= 0) return 0;
	if (op[id] == 1) {
		return sub(get(c[id].first , r + c[id].second - 1) , vp[id]);
	}
	else {
		if (r > len[c[id].first]) return add(val[c[id].first] , get(c[id].second , r - len[c[id].first]));
		return get(c[id].first , r);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	scanf("%s" , ch + 1);
	len[0] = strlen(ch + 1);
	for (int i = 1; i <= len[0]; i++) pre[i] = add(pre[i - 1] , ch[i]);
	val[0] = pre[len[0]];
	for (int i = 1; i < n; i++) {
		scanf("%s" , ch + 1);
		if (ch[1] == 'S') {
			int x;
			ll l,r;
			scanf("%d %lld %lld",&x,&l,&r); l++;
			op[i] = 1;
			c[i] = {x , l};
			len[i] = r - l + 1;
			vp[i] = get(x , l - 1);
			val[i] = sub(get(x , r) , vp[i]);
		}
		else {
			int x,y;
			scanf("%d %d",&x,&y);
			op[i] = 2;
			c[i] = {x , y};
			len[i] = len[x] + len[y];
			val[i] = add(val[x] , val[y]);
		}
	}
	printf("%lld\n" , val[n - 1]);
} 

