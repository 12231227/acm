#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uint64;

const int maxn = 1e6;
int cx = 0;
int cy = 0;
uint64 seed[5],two[55];
uint64 a[maxn + 11],b[maxn + 11];
uint64 state[2];
map<uint64 , vector<pair<int,uint64> > > mp;
vector<pair<int,uint64> > v;

uint64 xoroshiro128plus(uint64 s[2]) {
  uint64 s0 = s[0];
  uint64 s1 = s[1];
  uint64 result = s0 + s1;
  s1 ^= s0;
  s[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
  s[1] = (s1 << 36) | (s1 >> 28);
  return result;
}

struct node{
	pair<int,uint64> fi,se;
}x[maxn + 11],y[maxn + 11];

uint64 back(uint64 x,int n) { return x ^ ((x >> n) << n); }

map<uint64 , pair<int,int> > mpp;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= 4; i++) cin >> seed[i];
	two[0] = 1;
	for (int i = 1; i <= 50; i++) two[i] = two[i - 1] * 2;
	state[0] = seed[1]; state[1] = seed[1] ^ 0x7263d9bd8409f526;
	int up = max(15 , n / 3 + 1);
	for (int i = 1; i <= two[up]; i++) {
		a[i] = xoroshiro128plus(state);
		mp[back(a[i] , up)].push_back({i , a[i]});
	}
	state[0] = seed[2]; state[1] = seed[2] ^ 0x7263d9bd8409f526;
	for (int i = 1; i <= two[up]; i++) {
		b[i] = xoroshiro128plus(state);
		v = mp[back(b[i] , up)];
		for (auto pi : v) x[++cx] = {pi , {i , b[i]}};
		if (cx >= two[up]) break;
	}
	mp.clear();
	state[0] = seed[3]; state[1] = seed[3] ^ 0x7263d9bd8409f526;
	for (int i = 1; i <= two[up]; i++) {
		a[i] = xoroshiro128plus(state);
		mp[back(a[i] , up)].push_back({i , a[i]});
	}
	state[0] = seed[4]; state[1] = seed[4] ^ 0x7263d9bd8409f526;
	for (int i = 1; i <= two[up]; i++) {
		b[i] = xoroshiro128plus(state);
		v = mp[back(b[i] , up)];
		for (auto pi : v) y[++cy] = {pi , {i , b[i]}};
		if (cy >= two[up]) break;
	} 
	for (int i = 1; i <= cx; i++) {
		uint64 t = back(x[i].fi.second ^ x[i].se.second , n);
		mpp[t] = {x[i].fi.first , x[i].se.first};
	}
	for (int i = 1; i <= cy; i++) {
		uint64 t = back(y[i].fi.second ^ y[i].se.second , n);
		if (mpp.count(t)) {
			pair <int,int> pos = mpp[t];
			cout << pos.first << " " << pos.second << " " << y[i].fi.first << " " << y[i].se.first << " " << endl;
			return 0;
		}
	}
} 

