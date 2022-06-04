#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1000;

char ch[maxn + 11];
char ans[maxn + 11][maxn + 11];
pair<int,int> pos[30];
int has[maxn + 11][maxn + 11];
vector <int> hor[maxn + 11];
vector <int> vec[maxn + 11];
bool vis[maxn + 11][maxn + 11];
int ansl,ansr,ansu,ansd;
int up[maxn + 11],down[maxn + 11];

char upd(char c) { 
	if (c >= 'A' && c <= 'Z') return c + 'a' - 'A';
	return c;
} 

void solve(int u,int d,int l,int r) { 
	if (u > d || l > r) return;
	vector<pair<pair<int,int> , char> > tmp;
	for (int i = 1; i < 26; i++) {
		if (pos[i].first >= u && pos[i].first <= d && pos[i].second >= l && pos[i].second <= r) 
			tmp.pb(make_pair(make_pair(pos[i].first , pos[i].second) , 'a' + i));
	} 
	sort(tmp.begin() , tmp.end());
	int nowu = u;
	int j; 
	for (int i = 0; i < tmp.size(); i = j + 1) {
		j = i + 1;
		while (j < tmp.size() && tmp[j].first.first == tmp[i].first.first) j++; j--;
		int lef = l;
		for (int k = i; k < j; k++) {
			for (int p = nowu; p <= tmp[i].first.first; p++)
				for (int q = lef; q <= tmp[k].first.second; q++)
					if (ans[p][q] == '\0') ans[p][q] = tmp[k].second;
			lef = tmp[k].first.second + 1;
		}
		for (int p = nowu; p <= tmp[i].first.first; p++)
			for (int q = lef; q <= r; q++) if (ans[p][q] == '\0') ans[p][q] = tmp[j].second;
		nowu = tmp[i].first.first + 1;
		// int lef = l;
		// for (int k = i; k <= j; k++) {
		// 	int rig = k == j ? r : tmp[k].first.second;
		// 	for (int p = lef; p <= rig; p++)
		// 		for (int q = nowu; q <= tmp[i].first.first; q++)
		// 			if (ans[q][p] == '\0') ans[q][p] = tmp[k].second;
		// 	lef = tmp[k].first.second + 1;
		// }
		// nowu = tmp[i].first.first + 1;
	} 
	for (int i = nowu; i <= d; i++) { 
		for (int j = l; j <= r; j++) ans[i][j] = upd(ans[i - 1][j]);
	} 
} 

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < 26; i++) pos[i] = make_pair(0 , 0);
	int mini = 0;
	for (int i = 1; i <= m; i++) vec[i].pb(0);
	for (int i = 1; i <= n; i++) {
		scanf("%s",ch + 1);
		for (int j = 1; j <= m; j++){
			has[i][j] = has[i][j - 1];
			if (ch[j] != '.') { 
				if (mini == 0) mini = i;
				ans[i][j] = ch[j];
				pos[ch[j] - 'A'] = make_pair(i , j);
				has[i][j]++;
				vis[i][j] = false;
				if (ch[j] != 'A') {
					hor[i].pb(j);
					vec[j].pb(i);
				}
			} 
			else vis[i][j] = true;
		} 
	}
	int maxx = 0;
	int ansl,ansr,ansd,ansu;
	int x = pos[0].first, y = pos[0].second;
	for (int up = 1; up <= n; ++up) {
		for (int down = up; down <= n; ++down) {
			if (x < up || x > down) continue;
			int flag = 1, left = 1, right = m;
			for (int ch = 1; ch < 26; ++ch) {
				if (pos[ch].first < up || pos[ch].first > down) continue;
				if (pos[ch].second == y) flag = 0;
				else if (pos[ch].second < y) left = max(left, pos[ch].second + 1);
				else right = min(right, pos[ch].second - 1);
			}
			if (flag && (right - left + 1) * (down - up + 1) > maxx) {
				maxx = (right - left + 1) * (down - up + 1);
				ansu = up;
				ansd = down;
				ansl = left;
				ansr = right;
			} 
		}
	}
	for (int i = ansu; i <= ansd; ++i) {
		for (int j = ansl; j <= ansr; ++j) {
			ans[i][j] = 'a';
		} 
	} 
	ans[pos[0].first][pos[0].second] = 'A';
	solve(1, ansu - 1, 1, m);
	solve(ansu, ansd, 1, ansl - 1);
	solve(ansu, ansd, ansr + 1, m);
	solve(ansd + 1, n, 1, m);
//	for (int i = 1; i <= m; i++) vec[i].pb(n + 1);
//	int maxx = 0;
//	for (int l = pos[0].second; l >= 1; l--) { 
//		if (l != pos[0].second && vis[pos[0].first][l] == false) break;
//		int u,d; u = d = pos[0].first;
//		while (u > 1 && has[u - 1][pos[0].second] - has[u - 1][l - 1] == 0) u--;
//		while (d < n && has[d + 1][pos[0].second] - has[d + 1][l - 1] == 0) d++;
//		if (l == pos[0].second) up[l] = u; else up[l] = max(u , up[l + 1]);
//		if (l == pos[0].second) down[l] = d; else down[l] = min(down[l + 1] , d);
//	} 
//	for (int r = pos[0].second; r <= m; r++) {
//		if (r != pos[0].second && vis[pos[0].first][r] == false) break;
//		int u,d; u = d = pos[0].first;
//	 	while (u > 1 && has[u - 1][r] - has[u - 1][pos[0].second - 1] == 0) u--;
//	 	while (d < n && has[d + 1][r] - has[d + 1][pos[0].second - 1] == 0) d++;
//	 	if (r == pos[0].second) up[r] = u; else up[r] = max(up[r - 1] , u);
//	 	if (r == pos[0].second) down[r] = d; else down[r] = min(down[r - 1] , d);
//	}
//	for (int l = 1; l <= pos[0].second; l++)
//		for (int r = pos[0].second; r <= m; r++) {
//			int u = max(up[l] , up[r]);
//			int d = min(down[l] , down[r]);
//			if ((r - l + 1) * (d - u + 1) > maxx) { 
//				maxx = (r - l + 1) * (d - u + 1);
//				ansl = l; ansr = r;
//				ansu = u; ansd = d;
//			} 
//		} 
//	for (int i = ansl; i <= ansr; i++) 
//		for (int j = ansu; j <= ansd; j++) 
//			if (vis[j][i]) ans[j][i] = 'a';
	if (ansu > 1) solve(1 , ansu - 1 , 1 , m);
	if (ansl > 1) solve(ansu , ansd , 1 , ansl - 1);
	if (ansr < m) solve(ansu , ansd , ansr + 1 , m);
	if (ansd < n) solve(ansd + 1 , n , 1 , m);
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++) { 
			printf("%c",ans[i][j]);
		} 
		printf("\n");
	} 
} 

