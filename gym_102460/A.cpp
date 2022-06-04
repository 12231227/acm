#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int ans = 11;
int n = 0;
bool vis[11];
int a[8][8];
pair<pii,pii> vec[11];

bool check() { return a[3][5] == 1 && a[3][6] == 0; }
int remove() {
	int id = a[3][6];
	if (id == 0) return 0;
	if (vec[id].first.first == 3) return 1;
	if (vec[id].second.first == 3 && vec[id].first.first == 2) return 1;
	return -1;
}

void dfs(int step) { 
	if (check()) { ans = min(ans , step + 3); return; }
	if (step == 6) {
		if (vec[1].second == make_pair(3 , 5)) {
			int flag = remove();
			if (flag != -1) ans = min(ans , 9 + flag);
		}
		else if (vec[1].second == make_pair(3 , 4)) {
			if (!a[3][5] && !a[3][6]) ans = min(ans , 10);
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		pii s = vec[i].first;
		pii e = vec[i].second;
		if (vec[i].first.first == vec[i].second.first) {
			if (s.second > 1 && !a[s.first][s.second - 1]) {
				a[s.first][s.second - 1] = i; a[e.first][e.second] = 0;
				vec[i].first.second--; vec[i].second.second--;
				dfs(step + 1);
				vec[i].first = s; vec[i].second = e;
				a[s.first][s.second - 1] = 0; a[e.first][e.second] = i;
			}
			if (e.second < 6 && !a[e.first][e.second + 1]) {
				a[s.first][s.second] = 0; a[e.first][e.second + 1] = i;
				vec[i].first.second++; vec[i].second.second++;
				dfs(step + 1);
				vec[i].first = s; vec[i].second = e;
				a[s.first][s.second] = i; a[e.first][e.second + 1] = 0;
			}
		}
		else {
			if (s.first > 1 && !a[s.first - 1][s.second]) {
				a[s.first - 1][s.second] = i; a[e.first][e.second] = 0;
				vec[i].first.first--; vec[i].second.first--;
				dfs(step + 1);
				vec[i].first = s; vec[i].second = e;
				a[s.first - 1][s.second] = 0; a[e.first][e.second] = i;
			}
			if (e.first < 6 && !a[e.first + 1][e.second]) {
				a[s.first][s.second] = 0; a[e.first + 1][e.second] = i;
				vec[i].first.first++; vec[i].second.first++;
				dfs(step + 1);
				vec[i].first = s; vec[i].second = e;
				a[s.first][s.second] = i; a[e.first + 1][e.second] = 0;
			}
		}
	}
	
}

int main(){
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++) {
			scanf("%d",&a[i][j]); n = max(n , a[i][j]);
			if (a[i][j] == 0) continue;
			if (!vis[a[i][j]]) { vec[a[i][j]].first = {i , j}; vis[a[i][j]] = true; }
			else vec[a[i][j]].second = {i , j};
		}
	if (vec[1].first.first != vec[1].second.first || vec[1].first.first != 3) { printf("-1\n"); return 0; }
	if (vec[1].second == make_pair(3 , 6)) {
		printf("2\n");
		return 0;
	}
	dfs(0);
	printf("%d\n" , ans == 11 ? -1 : ans);
} 

