#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
map <vector <int> ,int> mp;
int a[111];
vector <int> v,vec;

int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for (int i = 0; i < (1 << 15); i++){
		v.clear();
		for (int j = 1; j <= n; j++){
			int cnt = 0;
			int num = i ^ a[j];
			for (int k = 0; k < 15; k++)
				if (num & (1 << k)) cnt++;
			v.push_back(cnt);
		}
		mp[v] = i;
	}
	int x = -1;
	for (int i = 0; i < (1 << 15); i++) {
		int o = (i << 15);
		vec.clear();
		for (int j = 1; j <= n; j++){
			int cnt = 0;
			int num = o ^ a[j];
			for (int k = 15; k < 30; k++)
				if (num & (1 << k)) cnt++;
			vec.push_back(cnt);
		}
		for (int k = 0; k <= 30; k++){
			v.clear();
			bool flag = true;
			for (int j = 0; j < n; j++) {
				if (k - vec[j] < 0 || k - vec[j] > 15) {
					flag = false;
					break;
				}
				v.push_back(k - vec[j]);
			}
			if (!flag) continue;
			if (mp[v]) { x = mp[v] + o; break; }
		}
		if (x != -1) break;
	}
	printf("%d\n" , x);
} 

