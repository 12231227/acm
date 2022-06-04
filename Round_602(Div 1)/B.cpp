#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
const int N = 40 * maxn;
int lson[N],rson[N],sum[N];
int T[maxn + 11],a[maxn + 11],pos[maxn + 11];
pair <int,int> p[maxn + 11];

int cnt = 0;
int build(int l,int r){
	int now = ++cnt;
	sum[now] = 0;
	if (l == r) return now;
	int mid = (l + r) >> 1;
	lson[now] = build(l,mid);
	rson[now] = build(mid + 1,r);
	return now;
} 

int update(int rt,int l,int r,int pos){ 
	int now = ++cnt;
	sum[now] = sum[rt] + 1;
	if (l == r) return now;
	int mid = (l + r) >> 1;
	if (mid >= pos) {
		rson[now] = rson[rt];
		lson[now] = update(lson[rt] , l ,mid , pos);
	}
	else{
		lson[now] = lson[rt];
		rson[now] = update(rson[rt] , mid + 1, r,pos);
	} 
	return now;
} 

int query(int st,int en,int l,int r,int k){
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int res = sum[lson[en]] - sum[lson[st]];
	if (res >= k) return query(lson[st] , lson[en] , l , mid , k);
	return query(rson[st] , rson[en] , mid + 1 , r ,k - res);
}

bool cmp(pair<int,int> a,pair<int,int> b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
} 

int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d" , &a[i]);
		p[i] = make_pair(a[i] , i);
	}
	sort(p + 1 , p + 1 + n , cmp);
	for (int i = 1; i <= n; i++) pos[i] = p[i].second;
	T[0] = build(1,n);
	for (int i = 1; i <= n; i++){
		int ind = pos[i];
		T[i] = update(T[i - 1] , 1 , n ,ind);
	} 
	int m;
	scanf("%d",&m);
	while (m--) { 
		int k,x;
		scanf("%d %d",&k,&x);
		int ind = query(T[0] , T[k] , 1 , n , x);
		printf("%d\n" , a[ind]);
	} 
} 

