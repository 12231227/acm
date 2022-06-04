#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x ; cin >> x;
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			printf("%d %d %d %d\n" , i , j , __gcd(i + x , j + x) , abs(i - j));
} 