#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int c0,c1,c2,c3;
		cin >> c0 >> c1 >> c2 >> c3;
		printf("Case #%d: " , i);
		if (c0 == 0) {
			if (c1 % 3 == 0) printf("Horse\n");
			else if (c1 % 3 == 1) {
				if (c2 == 0) printf("Horse\n"); else printf("Rabbit\n");
			}
			else printf("Rabbit\n");
			continue;
		}
		if (c0 % 2 == 1) {
			if (c1 == 0) {
				if (c2 + c3 == 0) printf("Horse\n"); else printf("Rabbit\n");
			}
			else if (c1 % 3 == 1) {
				if (c2 == 0) printf("Rabbit\n"); else printf("Horse\n");
			}
			else if (c1 % 3 == 2) {
				if (c2 <= 1) printf("Horse\n"); else printf("Rabbit\n");
			}
			else {
				printf("Rabbit\n");
			}
		}
		else {
			if (c1 == 0) {
				if (c2 + c3 == 0) printf("Rabbit\n"); else printf("Horse\n");
			}
			else if (c1 % 3 == 1) {
				if (c2 == 0) printf("Horse\n"); else printf("Rabbit\n");
			}
			else if (c1 % 3 == 2) {
				printf("Rabbit\n");
			}
			else {
				printf("Horse\n");
			}
		}
	} 
} 
