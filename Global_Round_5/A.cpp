#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		 if (x % 2 == 0) printf("%d\n" , x / 2);
		 else {
		 	if (res == 0) {
		 		res = 1;
				if (x < 0)  printf("%d\n" , x / 2); else printf("%d\n" , x / 2 + 1);
			} 
			else {
				res = 0;
				if (x < 0)  printf("%d\n" , x / 2 - 1); else printf("%d\n" , x / 2);
			}
		 }
	}
} 

