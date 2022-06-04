#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	if (n % 2 == 1) { printf("NO\n"); return 0; }
	int mx = 0;
	if (n >= 5) mx = 1 + (n - 5) / 2;
	if (k > mx) { printf("NO\n"); return 0; } 
	
} 
