#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e7;
unsigned a[maxn + 11];
unsigned ans[101];
struct node{
	int val,id;
	bool operator < (const node &rh) const {
		return val < rh.val;
	}
}b[101];

unsigned x,y,z;
unsigned rng61() {
	unsigned t;
	x = x ^ (x << 16);
	x = x ^ (x >> 5);
	x = x ^ (x << 1);
	t = x;
	x = y;
	y = z;
	z = (t ^ x) ^ y;
	return z;
}

int main(){ 
	int n,m;
	unsigned A,B,C;
	int ka = 0;
	while (~scanf("%d %d %u %u %u",&n,&m,&A,&B,&C)){
		ka++;
		x = A , y = B , z = C;
		for (int i = 1; i <= m; ++i) {
			scanf("%d" , &b[i].val);
			b[i].id = i;
		}
		for (int i = 0; i < n; ++i) a[i] = rng61();
		b[m + 1].val = -1;
		sort(b + 1 , b + 1 + m);
		b[m + 1].val = n;
		for (int i = m; i >= 1; --i) {
			if (b[i].val == b[i + 1].val) { ans[b[i].id] = ans[b[i + 1].id]; continue; }
			nth_element(a , a + b[i].val , a + b[i + 1].val);
			ans[b[i].id] = a[b[i].val];
		} 
		printf("Case #%d:",ka);
		for (int i = 1; i <= m; ++i) printf(" %u" , ans[i]); printf("\n");
	}
} 
