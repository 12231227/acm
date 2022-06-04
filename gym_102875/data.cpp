#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	int n = 5; printf("%d\n" , n);
	for (int i = 1; i <= n; i++) printf("%d " , rng() % 5 + 1); puts("");
	for (int i = 1; i <= n; i++) printf("%d " , rng() % 100 + 1); puts("");
	for (int i = 1; i <= n; i++) printf("%d " , rng() % 100 + 1); puts("");
}
