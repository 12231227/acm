#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

char s[211],t[5];
int f[211][211][211];

int main(){ 
	int n,lim; scanf("%d %d",&n,&lim);
	scanf("%s" , s + 1);
	scanf("%s" , t);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= lim; j++)
			for (int k = 0; k <= i; k++){
				if (s[i] != t[0] && s[i] != t[1]) {
					f[i][j][k] = f[i - 1][j][k] + f[i - 1][j - 1][k] + f[i - 1][j - 1][k - 1] + k;
				}
				else if (s[i] == t[0]) {
					f[i][j][k] = f[i - 1][j][k - 1] + f[i - 1][j - 1]
				}
			}
} 