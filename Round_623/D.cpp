#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;

const int maxn = 200000;
pii cat[maxn + 11];

int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) scanf("%d" , &cat[i].first);
	for (int i = 1; i <= n; i++) scanf("%d" , &cat[i].second);
	sort(cat + 1 , cat + 1 + n);
	ll ans = 0;
	priority_queue<int , vector<int> , less<int> > q;
	int last = cat[1].first; q.push(cat[1].second); ll sum = cat[1].second;
	int i = 2;
	while (i <= n) {
		if (cat[i].first == last) { q.push(cat[i].second); sum += cat[i].second; i++; continue; }
		sum -= q.top(); q.pop();
		ans += sum;
		if (q.empty()) {
			last = cat[i].first; sum += cat[i].second; q.push(cat[i].second); i++;
		}
		else last++;
	}
	while (!q.empty()) {
		sum -= q.top(); q.pop();
		ans += sum;
	}
	printf("%lld\n" , ans);
} 

