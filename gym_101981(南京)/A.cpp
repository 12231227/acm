#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	if (n == 0) printf("Austin\n");
	else if (n <= k) printf("Adrien\n");
	else if (k == 1) {
		if (n % 2 == 1) printf("Adrien\n"); else printf("Austin\n");
	}
	else printf("Adrien\n");
}

