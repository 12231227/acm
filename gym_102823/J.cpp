#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int sg[100][100][100];

bool check(int a,int b,int c) {
	if (a < 0 || b < 0 || c < 0) return false;
	if (a == b || b == c) return false;
	return true;
}

int dfs(int a,int b,int c) { 
	if (sg[a][b][c] != -1) return sg[a][b][c];
	int nxt = 1;
	if (check(a - 1 , b , c)) nxt &= dfs(a - 1 , b , c);
	if (check(a , b - 1 , c)) nxt &= dfs(a , b - 1 , c);
	if (check(a , b , c - 1)) nxt &= dfs(a , b , c - 1);
	if (!nxt) return sg[a][b][c] = 1;
	return sg[a][b][c] = 0;
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(sg , -1 , sizeof(sg));
	for (int i = 50; i >= 1; i--)
		for (int j = 50; j >= 1; j--)
			for (int k = 50; k >= 1; k--)
				dfs(i , j , k);
	int a;
	cin >> a;
	for (int b = 1; b <= 50; b++ , cout << endl)
		for (int c = 1; c <= 50; c++){
			if (!check(a , b , c)) cout << "F ";
			else if (sg[a][b][c]) cout << "A ";
			else cout << "B ";
		} 
} 
