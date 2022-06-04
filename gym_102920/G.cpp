#pragma GCC optimize("Ofast", 2)
#include<bits/stdc++.h>
# define fi first
# define se second
# define ll long long
# define sz(x) (int)(x).size()
# define all(x) (x).begin(),(x).end()
# define rep(i,k,n) for (int i=k;i<n;i++)
# define pb push_back
# define mp make_pair
# define INF (1<<31-1)
# define pii pair<int,int>
using namespace std;
int n;
ll d;
const int maxn = 1e6 + 10;
ll a[maxn];
ll ans[maxn];
int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d%lld", &n, &d);
	rep(i, 0, n)
	scanf("%lld", &a[i]);
	ll minnn = 0;
	ll maxnn = 0;
	rep(i, 1, n)
	{
		ans[i] = a[i] - (ll) i * d - a[0];
		//	cout << ans[i] << ' ';
		minnn = min(ans[i], minnn);
		maxnn = max(maxnn, ans[i]);
	}
	//cout << endl;
	printf("%lld", (abs(maxnn - minnn)) / 2);
	if ((maxnn - minnn) % 2) printf(".5\n"); else printf(".0\n");

} 
