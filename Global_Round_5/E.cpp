#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if (n <= 5) { 
		printf("%d\n" , n == 3 ? 0 : 1);
		return 0;
	} 
	int cnt = 4;
	int root = 2;
	while (cnt + 1 < n) {
		int rig = cnt + 1 + root;
		root = cnt + 1;
		cnt = 2 * cnt + 1;
		if ((root + rig) % 2 == 1) cnt++;
	} 
	if (cnt == n || cnt + 1 == n) printf("1\n"); else printf("0\n");
} 

