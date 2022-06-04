#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

vector <int> v;

struct node {
	int a,b,c,d;
	bool operator == (const node &rh) const {
		return a == rh.a && b == rh.b && c == rh.c && d == rh.d;
	}
	bool operator < (const node &rh) const {
		if (a != rh.a) return a < rh.a;
		if (b != rh.b) return b < rh.b;
		if (c != rh.c) return c < rh.c;
		return d < rh.d;
	}
};

int calc(int x1,int y1,int x2,int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int d0,d1,d2; 
	while (cin >> d0 >> d1) {
		if (d0 > d1) swap(d0 , d1);
		v.clear();
		for (int i = -d0; i <= d0; i++)
			for (int j = -d1; j <= d1; j++) {
				int i1 = d0 - abs(i);
				int i2 = -i1;
				int j1 = d1 - abs(j);
				int j2 = -j1;
				set <node> s;
				s.insert(node{i , i1 , j , j1});
				s.insert(node{i , i2 , j , j1});
				s.insert(node{i , i1 , j , j2});
				s.insert(node{i , i2 , j , j2});
				for (auto pi : s)
					v.pb(calc(pi.a , pi.b , pi.c , pi.d));
			}
		sort(all(v));
		int last = v[0] , cnt = 1;
		for (int i = 1; i < v.size(); i++)
			if (v[i] == last) cnt++;
		else {
			printf("%d %d\n" , last , cnt);
			cnt = 1; last = v[i];
		}
		printf("%d %d\n" , last , cnt);
		puts("------------------");
	}
} 
