#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int ans[maxn + 11];
vector <pair<int,int> > seg;
set <int> s;

int main(){
	int t;
	scanf("%d" , &t);
	while (t--) {
		int n;
		scanf("%d" , &n);
		seg.clear();
		s.clear();
		for (int i = 1; i <= n; i++) {
			int l,r;
			scanf("%d %d",&l,&r);
			ans[i] = 0;
			seg.emplace_back(make_pair(l , -i));
			seg.emplace_back(make_pair(r , i));
		}
		int cnt = 0;
		sort(seg.begin() , seg.end());
		for (int i = 0; i < seg.size(); i++) {
			pair <int,int> pi = seg[i];
			if (pi.second < 0) {
				s.insert(-pi.second);
				if (s.size() == 1 && seg[i + 1].second == -pi.second) ans[-pi.second]--;
			}
			else {
				s.erase(pi.second);
				if (s.size() == 1 && i + 1 < seg.size() && seg[i + 1].second < 0)
					ans[*s.begin()]++;
			}
			if (s.size() == 0) cnt++;
		}
		int mx = 0;
		for (int i = 1; i <= n; i++) mx = max(ans[i] + cnt , mx);
		printf("%d\n" , mx);
	}
} 

