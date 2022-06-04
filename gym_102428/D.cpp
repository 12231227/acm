#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;

map <pair<int,int> , int> mp;
set <pair<int,int> > s;

int x[maxn + 11],y[maxn + 11],b[maxn + 11];

int gcd(int a,int b) { return b == 0 ? a : gcd(b , a % b); }

int main(){
	int n;
	scanf("%d",&n); 
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d",&x[i],&y[i],&b[i]);
	} 
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			if (b[i] == b[j]) continue;
			if (b[i] < b[j]) { 
				int g = gcd(abs(x[j] - x[i]) , abs(y[j] - y[i]));
				mp[make_pair((x[j] - x[i]) / g , (y[j] - y[i]) / g)] = 1;
				int tx = (x[j] - x[i]) / g; int ty = (y[j] - y[i]) / g;
				if (mp.count(make_pair(-tx , -ty))) { s.insert(make_pair(max(tx, ty) , min(tx , ty)));  }
			} 
			else { 
				int g = gcd(abs(x[i] - x[j]) , abs(y[i] - y[j]));
				mp[make_pair((x[i] - x[j]) / g , (y[i] - y[j]) / g)] = 1;
				int tx = (x[i] - x[j]) / g; int ty = (y[i] - y[j]) / g;
				if (mp.count(make_pair(-tx , -ty))) { s.insert(make_pair(max(tx, ty) , min(tx , ty)));  }
			} 
		} 
	if (s.size() >= 2) printf("N\n"); else printf("Y\n");
} 

