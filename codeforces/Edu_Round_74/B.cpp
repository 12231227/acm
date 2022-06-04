#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int x[maxn + 11];
vector <int> v;

bool cmp(int a,int b) { return a > b; }

int main(){
	int q;
	cin >> q;
	while (q--) {
		v.clear();
		int n,r;
		cin >> n >> r;
		for (int i = 1; i <= n; i++) { int x; cin >> x; v.push_back(x); }
		sort(v.begin() , v.end() , cmp);
		v.erase(unique(v.begin() , v.end()) , v.end());
		int now = 0;
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int pos = v[i] - now;
			if (pos > 0) cnt++; else break; 
			now += r;
		}
		printf("%d\n",cnt);
	}
}

