#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1 << 19];
int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
	ll ans = 0;
	priority_queue<int , vector<int> , greater<int> > q;
	for (int i = n; a[i] != -1; i--) {
		q.push(a[i]);
		if (!(i&(i - 1))) {
			ans += q.top();
			q.pop();
		}
	}
	printf("%lld\n" , ans);
} 
