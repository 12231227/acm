#include <bits/stdc++.h>
using namespace std;

int m;

bool check(int n) {
	int pre = 0;
	int sum1 = n;
	int sum2 = 0;
	while (n) {
		int x = n % 10;
		n /= 10;
		pre += x;
		sum2 += x * x;
	}
	sum2 = (pre * pre - sum2) / 2;
	return sum1 %  m == sum2 % m;
}

int main() { 
	int l,r;
	cin >> l >> r >> m;
	for (int i = 1; i <= r; i++)
		if (check(i)) printf("%d\n" , i);
} 

