#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--) {
		int a[5];
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		int cnt = 0;
		for (int i = 0; i < 4; i++)
			if (a[i] != 0) cnt++;
		if (cnt == 0) printf("Typically Otaku\n");
		else if (cnt == 1) printf("Eye-opener\n");
		else if (cnt == 2) printf("Young Traveller\n");
		else if (cnt == 3) printf("Excellent Traveller\n");
		else printf("Contemporary Xu Xiake\n");
	}
}

