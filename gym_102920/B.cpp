#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[10],b[10];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 6; i++) cin >> a[i];
	for (int i = 1; i <= 6; i++) cin >> b[i];
	int x = 0 , y = 36;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			if (a[i] > b[j]) x++;
	int g = __gcd(x , y);
	x /= g; y /= g;
	cout << x << "/" << y << endl;
} 
