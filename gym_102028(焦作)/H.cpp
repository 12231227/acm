	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<cmath>
	#include<algorithm>
	#include<vector>
	#include <stack>
	#define all(x) (x).begin(),(x).end()
	#define ll long long
	using namespace std;
	
	const int maxn = 2e5 + 11;
	const int inf = 1e6 + 11;
	
	int inputs[maxn];
	ll cont[maxn + 11];
	int st[maxn + 11][30];
	int pos[maxn + 11];
	int lg;
	int sss[maxn];
	int t1[maxn];
	int t2[maxn];
	int c[maxn];
	int sa[maxn];
	int rk[maxn];
	int height[maxn];
	vector<int> v;
	
	bool cmp(int *r, int a, int b, int l) {
		return r[a] == r[b] && r[a + l] == r[b + l];
	}
	
	void suffixsort(int str[], int sa[], int rk[], int height[], int n, int m) {
		n++;
		int p;
		for (int i = 0; i < m; i++)
			c[i] = 0;
		for (int i = 0; i < n; i++) {
			t1[i] = str[i];
			c[t1[i]]++;
		}
		for (int i = 1; i < m; i++)
			c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--)
			sa[--c[t1[i]]] = i;
		for (int j = 1; j <= n; j <<= 1) {
			p = 0;
			for (int i = n - j; i < n; i++)
				t2[p++] = i;
			for (int i = 0; i < n; i++)
				if (sa[i] >= j)
					t2[p++] = sa[i] - j;
			for (int i = 0; i < m; i++)
				c[i] = 0;
			for (int i = 0; i < n; i++)
				c[t1[t2[i]]]++;
			for (int i = 1; i < m; i++)
				c[i] += c[i - 1];
			for (int i = n - 1; i >= 0; i--)
				sa[--c[t1[t2[i]]]] = t2[i];
			swap(t1, t2);
			p = 1; t1[sa[0]] = 0;
			for (int i = 1; i < n; i++)
				t1[sa[i]] = cmp(t2, sa[i - 1], sa[i], j) ? p - 1 : p++;
			if (p >= n)
				break;
			m = p;
		}
		int k = 0;
		n--;
		for (int i = 0; i <= n; i++)
			rk[sa[i]] = i;
		for (int i = 0; i < n; i++) {
			if (k)
				k--;
			int j = sa[rk[i] - 1];
			while (str[i + k] == str[j + k])
			{
				k++;
			}
			height[rk[i]] = k;
		}
	}
	
	int Log(int x) { if (x <= 0) return 0; for (int i = 0; ; i++) if ((1 << i) > x) return i - 1; } 
	
	stack <pair<int,int> > s;
	
	int main() {
		int T;
		scanf("%d", &T);
		while (T--)
		{
			int n;
			scanf("%d", &n);
			v.clear();
			for (int i = 0; i < n; i++) {
				scanf("%d", &inputs[i]);
				v.push_back(inputs[i]);
			} 
			sort(all(v));
			v.erase(unique(all(v)), v.end());
			int m = v.size();
			for (int i = 0; i < n; i++) { 
				sss[i] = lower_bound(all(v), inputs[i]) - v.begin() + 1;
			} 
			sss[n]=0;
			suffixsort(sss, sa, rk, height, n, m + 5);
			while (!s.empty()) s.pop();
			inputs[n] = inf;
			for (int i = 0; i <= n; i++) { 
				while (!s.empty() && inputs[i] > s.top().first) { pos[s.top().second] = i; s.pop(); }
				s.push(make_pair(inputs[i] , i));
			} 
			cont[n] = 0;
			for (int i = n - 1; i >= 0; i--) cont[i] = cont[pos[i]] + 1ll * (pos[i] - i) * inputs[i];
			lg = Log(n + 1);
			for (int i = 0; i < n; i++) st[i][0] = pos[i]; st[n][0] = n;
			for (int j = 1; j <= lg; j++) 
			 for (int i = 0; i <= n; i++) 
			  st[i][j] = st[st[i][j - 1]][j - 1];
			ll ans = cont[sa[1]];
			for (int i = 2; i <= n; i++) { 
				int p = sa[i] + height[i];
				if (height[i] == 0) ans += cont[sa[i]];
				else { 
				 int sta = sa[i];
				 int up=Log(n-sa[i]);
				 for (int j=up;j>=0;j--) 
	                if (st[sta][j]<=p) sta=st[sta][j];
					ans += 1ll * inputs[sta] * (pos[sta] - p) + cont[pos[sta]];
				} 
			} 
			cout << ans << endl;
		} 
	} 

