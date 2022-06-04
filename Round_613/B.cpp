#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e9;

int main(){
	int t;
	scanf("%d" , &t);
	while (t--){
		int n;
		scanf("%d" , &n);
		ll sum = 0;
		ll mx = -inf;
		ll minn = 0;
		int l = 0;
		for (int i = 1; i <= n; i++) { 
			int x;
			scanf("%d" , &x); sum += x;
			if (i == n && l == 0) continue;
			mx = max(mx , sum - minn);
			if (sum <= minn) {
				minn = sum;
				l = i;
			}
		} 
		if (mx >= sum) printf("NO\n");
		else printf("YES\n");
	} 
} 

