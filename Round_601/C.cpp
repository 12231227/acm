#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

pair<int,int> v[maxn + 11];
map <pair<int,int> , vector <int> > mp;
int cnt[maxn + 11];
int a[44];
 
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n - 2; i++) {
		scanf("%d %d %d",&a[1],&a[2],&a[3]);
		cnt[a[1]]++;
		cnt[a[2]]++;
		cnt[a[3]]++;
		sort(a + 1 , a + 4);
		v[a[1]] = make_pair(a[2] , a[3]);
		v[a[2]] = make_pair(a[1] , a[3]);
		v[a[3]] = make_pair(a[1] , a[2]);
		mp[make_pair(a[1] , a[2])].push_back(a[3]);
		mp[make_pair(a[1] , a[3])].push_back(a[2]);
		mp[make_pair(a[2] , a[3])].push_back(a[1]);
	} 
	int s = 0;
	for (int i = 1; i <= n; i++) 
		if (cnt[i] == 1) { s = i; break; }
	int x = v[s].first; int y = v[s].second;
	pair<int,int> pi = make_pair(min(x , y) , max(x , y));
	int z1 = mp[pi][0];
	int z2 = mp[pi][1];
	int z = z1 == s ? z2 : z1;
	if (mp[make_pair(min(x , z) , max(x , z))].size() == 2) {
			swap(x , y);
		}
	printf("%d %d %d ", s , x , y);
	for (int i = 4; i <= n; i++) {
		pi = make_pair(min(x , y) , max(x , y));
		z1 = mp[pi][0];
		z2 = mp[pi][1];
		z = z1 == s ? z2 : z1;
		printf("%d ",z);
		s = x;
		x = y;
		y = z;
	}
} 
