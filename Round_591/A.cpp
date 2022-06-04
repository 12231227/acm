#include <bits/stdc++.h>
#define pb emplace_back
#define all(x) (x).begin(),(x).end()

using namespace std;
int main(){
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n == 2) printf("2\n");
		else if (n % 2 == 0) printf("0\n");
		else printf("1\n");
	}
}

