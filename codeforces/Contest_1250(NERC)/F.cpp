#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int l = 1;
	for (int i = 2; i * i <= n; i++)
		if (n %  i == 0) l = i;
	int r = n / l;
	cout << (l + r) * 2 << endl;
} 

