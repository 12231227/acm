#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

vector <pii> ans;
vector <int> dir;
map <int , vector <int> > cx,cy;
map <int,int> cntx,cnty;
char ch[55];

int main(){ 
	scanf("%s" , ch + 1);
	int n = strlen(ch + 1);
	// 0 - L 1 - R 2 - U 3 - D
	for (int i = 1; i <= n; i++) {
		if (ch[i] == 'L') dir.pb(0);
		else if (ch[i] == 'R') dir.pb(1);
		else if (ch[i] == 'U') dir.pb(2);
		else if (ch[i] == 'D') dir.pb(3);
	}
	int step = 1;
	int x = 0 , y = 0;
	for (int i = 0; i < n; i++) {
		if (dir[i] == 2) { 
			if (cx[x].size() < 2){
				y += step; ans.pb(make_pair(x , y + 1)); cx[x].pb(y);
			}
			else y = max(cx[x][0] , cx[x][1]);
		}
		if (dir[i] == 3) { 
			if (cx[x].size() < 2){
				y -= step; ans.pb(make_pair(x , y - 1)); cx[x].pb(y);
			}
			else y = min(cx[x][0] , cx[x][1]);
		}
		if (dir[i] == 0) { 
			if (cy[y].size() < 2){
				x -= step; ans.pb(make_pair(x - 1 , y)); cy[y].pb(x);
			}
			else x = min(cy[y][0] , cy[y][1]);
		}
		if (dir[i] == 1) { 
			if (cy[y].size() < 2){
				x += step; ans.pb(make_pair(x + 1 , y)); cy[y].pb(x);
			}
			else x = max(cy[y][0] , cy[y][1]);
		}
		if (dir[i] <= 1) cnty[y]++; else cntx[x]++;
		step *= 2;
	}
	if (cntx[x] > 2 || cnty[y] > 2) printf("impossible\n");
	else {
		printf("%d %d\n" , - x , -y);
		printf("%d\n" , ans.size());
		for (auto pi : ans) printf("%d %d\n" , pi.first - x , pi.second - y);
	}
} 
