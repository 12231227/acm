#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	priority_queue <int,vector<int>,greater<int> > q;
	scanf("%d",&t);
	while (t--) {
		while (!q.empty()) q.pop();
		int n;
		scanf("%d",&n);
		while (n--) {
			int x;
			scanf("%d",&x);
			q.push(x);
		}
		int ans = 0;
		while (q.size() > 1) {
			int x = q.top(); q.pop();
			int y = q.top(); q.pop();
			ans += x + y;
			q.push(x + y);
		}
		printf("%d\n" , ans);
	}
}