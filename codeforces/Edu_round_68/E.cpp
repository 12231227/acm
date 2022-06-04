#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e4;

int len;
int bit[maxn + 11];
int lowbit(int x) { return x & (-x); }
void update(int x,int val) { for (; x <= len; x += lowbit(x)) bit[x] += val; } 
int query(int x) { int ans = 0; if (x < 0) return 0; for (; x ; x -= lowbit(x)) ans += bit[x]; return ans; } 

struct node{
	int x1,x2,y1,y2;
}a[maxn + 11];
vector <int> x,y;
vector <pair<int,int> > out[maxn + 11];
vector <pair<int,pair<int,int> > > ver,hor;

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		x.push_back(a[i].x1); x.push_back(a[i].x2);
		y.push_back(a[i].y1); y.push_back(a[i].y2);
	} 
	sort(x.begin() , x.end()); sort(y.begin() , y.end());
	x.erase(unique(x.begin() , x.end()) , x.end());
	len = x.size();
	y.erase(unique(y.begin() , y.end()) , y.end());
	for (int i = 1; i <= n; i++){
		int x1,x2,y1,y2;
		x1 = lower_bound(x.begin(),x.end(),a[i].x1) - x.begin() + 1;
		x2 = lower_bound(x.begin(),x.end(),a[i].x2) - x.begin() + 1;
		y1 = lower_bound(y.begin(),y.end(),a[i].y1) - y.begin() + 1;
		y2 = lower_bound(y.begin(),y.end(),a[i].y2) - y.begin() + 1;
		if (x1 == x2) {
			if (y1 > y2) swap(y1 , y2);
			out[y2].push_back(make_pair(x1 , y1));
			ver.push_back(make_pair(x1 , make_pair(y1 , y2)));
		}
		if (y1 == y2) hor.push_back(make_pair(y1 , make_pair(min(x1 , x2) , max(x1 , x2))));
	} 
	sort(ver.begin(),ver.end()); sort(hor.begin(),hor.end());
	ll ans = 0;
	for (int i = 0; i < hor.size(); i++) { 
		int l = hor[i].second.first;
		int r = hor[i].second.second;
		memset(bit,0,sizeof(bit));
		for (int j = 0; j < ver.size(); j++) {
			if (ver[j].first < l || ver[j].first > r) continue;
			int down = ver[j].second.first;
			int up = ver[j].second.second;
			if (up <= hor[i].first || down > hor[i].first) continue;
			update(ver[j].first , 1);
		}
		int now = hor[i].first + 1;
		for (int j = i + 1; j < hor.size(); j++) { 
			while (now < hor[j].first) { 
				for (int k = 0; k < out[now].size(); k++) { 
					if (out[now][k].first < l || out[now][k].first > r || out[now][k].second > hor[i].first) continue;
					update(out[now][k].first , -1);
				} 
				now++;
			} 
			int L = hor[j].second.first;
			int R = hor[j].second.second;
			if (L >= r || R <= l) continue;
			L = max(L , l); R = min(R , r);
			int cnt = query(R) - query(L - 1);
			ans += 1ll * cnt * (cnt - 1) / 2;
		} 
	}
	cout << ans << endl;
} 

