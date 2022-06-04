#include <bits/stdc++.h>
using namespace std;

const int maxn = (1 << 25);

int cnt = 0;
int dx[4] = {0 , 0 , 1 , -1};
int dy[4] = {1 , -1 , 0 , 0};
int n,tot;
int mp[11][11];
int a[11][11];
bool vis[11][11];
vector <pair<int,int> > s[111];
int tag[11][11];
int rec[maxn + 11];

bool check(int x) { return x > 0 && x <= n; }

void dfs_w(int x,int y,int id) {
	tag[x][y] = id; vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (check(X) && check(Y) && a[X][Y] == 0 && !vis[X][Y]) dfs_w(X , Y , id);
	}
}

int find(int x,int y) {
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (check(X) && check(Y) && tag[X][Y]) return tag[X][Y];
	}
	return 0;
}

int mex(vector <int> s) {
	sort(s.begin() , s.end());
	s.erase(unique(s.begin() , s.end()) , s.end());
	int now = 0;
	for (auto x : s) {
		if (x != now) return now;
		now++;
	}
	return now;
}

int get(int bin,int id) {
	if (rec[bin] != -1) return rec[bin];
	vector <int> sg;
	for (int i = 0; i < tot; i++) {
		if (bin & (1 << i)) continue;
		int to = bin ^ (1 << i);
		for (int j = 0; j < 4; j++) { 
			int X = s[id][i].first + dx[j];
			int Y = s[id][i].second + dy[j];
			if (!check(X) || !check(Y) || mp[X][Y] == -1) continue;
			if (to & (1 << mp[X][Y])) continue;
			to ^= (1 << mp[X][Y]);
		} 
		sg.push_back(get(to , id));
	}
	return rec[bin] = mex(sg);
}

void dfs_f(int x,int y,int id,int p) {
	s[id].push_back({x , y}); vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (check(X) && check(Y) && a[X][Y] == 1 && !vis[X][Y] && find(X , Y) == p) dfs_f(X , Y , id , p);
	}
}

int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		char ch[15];
		scanf("%s" , ch + 1);
		for (int j = 1; j <= n; j++)
			if (ch[j] == '*') a[i][j] = 0;
			else if (ch[j] == '.') a[i][j] = 1;
			else a[i][j] = 2;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != 0 || vis[i][j]) continue;
			dfs_w(i , j , ++cnt);
		}
	int id = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != 1 || vis[i][j]) continue;
			int at = find(i , j); if (!at) continue;
			dfs_f(i , j , ++id , at);
		}
	int ans = 0;
	for (int i = 1; i <= id; i++)
		if (!s[i].empty()) {
			tot = 0;
			memset(mp , -1 , sizeof(mp));
			for (auto pi : s[i]) mp[pi.first][pi.second] = tot++;
			for (int j = 0; j < (1 << tot); j++) rec[j] = -1;
			ans ^= get(0 , i);
		}
	if (!ans) printf("Second player will win\n");
	else printf("First player will win\n");
} 

