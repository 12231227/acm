#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 3e5;

pair<int,int> a[maxn + 11];
ll jc[maxn + 11];
vector <int> n3;
int n2[maxn + 11],n1[maxn + 11];

bool cmp1(pair<int,int> a, pair<int,int> b){
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d %d",&a[i].first,&a[i].second);
	sort(a + 1,a + 1 + n ,cmp1);
	for (int i = 1; i <= n; i++) { n1[a[i].first]++; n2[a[i].second]++; }
	jc[0] = jc[1] = 1;
	for (int i = 2; i <= n; i++) jc[i] = jc[i - 1] * i % mol;
	ll ans = jc[n];
	ll res = 1;
	for (int i = 1; i <= n; i++) res = res * jc[n1[i]] % mol;
	ans = (ans - res + mol) % mol;
	res = 1;
	for (int i = 1; i <= n; i++) res = res * jc[n2[i]] % mol;
	ans = (ans - res + mol) % mol;
	bool can = true;
	for (int i = 2; i <= n; i++)
	 if (a[i].second < a[i - 1].second) { can = false ; break; }
	if (!can) printf("%lld\n",ans);
	else{
		ll res = 1;
		int cnt = 1;
		for (int i = 2; i <= n; i++) {
			if (a[i].first == a[i - 1].first){
				if (a[i].second == a[i - 1].second) cnt++;
				else { res = res * jc[cnt] % mol; cnt = 1; }
			} else {
				res = res * jc[cnt] % mol;
				cnt = 1;
			}
		}
		res = res * jc[cnt] % mol;
		ans = (ans + res) % mol;
		printf("%lld\n",ans);
	}
} 

