#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6;
int a[maxn + 11];
ll sum[maxn + 11];

int main(){
	int n;
	scanf("%d" , &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]) , sum[i] = sum[i - 1] + a[i];
	stack <pair<ll ,int> > s;
	s.push(make_pair(0 , 0));
	for (int i = 1; i <= n; i++) {
		pair<ll , int> pi = make_pair(sum[i] , i);
		if (s.size() <= 1) { s.push(pi); continue; }
		while (s.size() > 1) {
			pair <ll,int> tmp = s.top(); s.pop();
			if ((pi.first - s.top().first) * (tmp.second - s.top().second) >= (tmp.first - s.top().first) * (pi.second - s.top().second))
				{ s.push(tmp); break; }
		} 
		s.push(pi);
	} 
	vector <int> upd;
	while (!s.empty()) { upd.push_back(s.top().second); s.pop(); }
	reverse(upd.begin() , upd.end());
	int last = 0;
	for (int i = 1; i < upd.size(); i++) {
		int p = upd[i];
		double ans = 1.0 * (sum[p] - sum[last]) / (p - last);
		for (int i = last + 1; i <= p; i++)
			printf("%.10lf\n" , ans);
		last = p;
	}
} 

