#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const double lg = 0.30102999566398;

int main(){ 
	int m;
	int c = 0;
	while (~scanf("%d",&m)) { 
		c++;
		printf("Case #%d: " , c);
		printf("%d\n" , (int)(m * log(2) / log(10)));
	} 
} 
