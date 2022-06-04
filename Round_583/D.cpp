#include <cstdio>
#include <cstring>
using namespace std;
 
const int maxn =1000000;
 
char ch[maxn + 11];
bool vis[maxn + 11];
bool lef[maxn + 11],rig[maxn + 11],up[maxn + 11],down[maxn + 11];
int mp[maxn + 11];
int n,m;
 
bool check(){
	memset(vis,false,sizeof(vis));
	vis[0] = true;
	for (int i = 0; i < n; i++)
	 for (int j = 0; j < m; j++)
	 if (mp[i * m + j]){
	  if (j) vis[i * m + j] = vis[i * m + j - 1];
	  if (i) vis[i * m + j] = vis[i * m + j] | vis[i * m + j - m];
	}
	return vis[n * m - 1];
}
 
bool in(int x,int y) { return (x >= 0 && x < n && y >= 0 && y < m); }

void dfsr(int x,int y){
	int ind = x * m + y;
	if (rig[ind]) return;
	rig[ind] = true;
	if (in(x , y + 1) && mp[ind + 1] == 0) dfsr(x , y + 1);
	if (in(x - 1, y + 1) && mp[ind + 1 - m] == 0) dfsr(x - 1 , y + 1);
	if (in(x + 1, y + 1) && mp[ind + 1 + m] == 0) dfsr(x + 1 , y + 1);
}
 
void dfsl(int x,int y){
	int ind = x * m + y;
	if (lef[ind]) return;
	lef[ind] = true;
	if (in(x, y - 1) && mp[ind - 1] == 0) dfsl(x , y - 1);
	if (in(x - 1, y - 1) && mp[ind - 1 - m] == 0) dfsl(x - 1 ,y - 1);
	if (in(x + 1, y - 1) && mp[ind - 1 + m] == 0) dfsl(x + 1 ,y - 1);
}
 
void dfsu(int x,int y){
	int ind = x * m + y;
	if (up[ind]) return;
	up[ind] = true;
	if (in(x - 1 , y) && mp[ind - m] == 0) dfsu(x - 1, y);
	if (in(x - 1, y - 1) && mp[ind - m - 1] == 0) dfsu(x - 1 , y - 1);
	if (in(x - 1, y + 1) && mp[ind - m + 1] == 0) dfsu(x - 1 , y + 1);
}
 
void dfsd(int x,int y){
	int ind = x * m + y;
	if (down[ind]) return;
	down[ind] = true;
	if (in(x + 1 , y) && mp[ind + m] == 0) dfsd(x + 1 , y);
	if (in(x + 1, y - 1) && mp[ind + m - 1] == 0) dfsd(x + 1, y - 1);
	if (in(x + 1, y + 1) && mp[ind + m + 1] == 0) dfsd(x + 1, y + 1);
}
 
bool judge(int x,int y){
	int ind = x * m + y;
	bool l,r,u,d;
	l = r = u = d = false;
	if (in(x , y - 1) && rig[ind - 1]) l = true;
	if (in(x - 1, y - 1) && rig[ind - 1 - m]) l = true;
	if (in(x + 1, y - 1) && rig[ind - 1 + m]) l = true;
	if (in(x - 1, y) && rig[ind - m]) l = true;
	if (in(x + 1, y) && rig[ind + m]) l = true;
	if (in(x - 1 , y + 1) && rig[ind + 1 - m]) l = true;
	if (in(x + 1 , y + 1) && rig[ind + 1 + m]) l = true;
	if (in(x , y + 1) && rig[ind + 1]) l = true;
	
	if (in(x , y - 1) && lef[ind - 1]) r = true;
	if (in(x - 1, y - 1) && lef[ind - 1 - m]) r = true;
	if (in(x + 1, y - 1) && lef[ind - 1 + m]) r = true;
	if (in(x - 1, y) && lef[ind - m]) r = true;
	if (in(x + 1, y) && lef[ind + m]) r = true;
	if (in(x - 1 , y + 1) && lef[ind + 1 - m]) r = true;
	if (in(x + 1 , y + 1) && lef[ind + 1 + m]) r = true;
	if (in(x , y + 1) && lef[ind + 1]) r = true;
	
	if (in(x , y - 1) && up[ind - 1]) d = true;
	if (in(x - 1, y - 1) && up[ind - 1 - m]) d = true;
	if (in(x + 1, y - 1) && up[ind - 1 + m]) d = true;
	if (in(x - 1, y) && up[ind - m]) d = true;
	if (in(x + 1, y) && up[ind + m]) d = true;
	if (in(x - 1 , y + 1) && up[ind + 1 - m]) d = true;
	if (in(x + 1 , y + 1) && up[ind + 1 + m]) d = true;
	if (in(x , y + 1) && up[ind + 1]) d = true;

	if (in(x , y - 1) && down[ind - 1]) u = true;
	if (in(x - 1, y - 1) && down[ind - 1 - m]) u = true;
	if (in(x + 1, y - 1) && down[ind - 1 + m]) u = true;
	if (in(x - 1, y) && down[ind - m]) u = true;
	if (in(x + 1, y) && down[ind + m]) u = true;
	if (in(x - 1 , y + 1) && down[ind + 1 - m]) u = true;
	if (in(x + 1 , y + 1) && down[ind + 1 + m]) u = true;
	if (in(x , y + 1) && down[ind + 1]) u = true;

	if (l && r) return true;
	if (l && u) return true;
	if (u && d) return true;
	if (d && r) return true;
	if (ind % m == 0 && (r || u)) return true;
	if ((ind + 1) % m == 0 && (l || d)) return true;
	if (ind < m && (d || l)) return true;
	if (ind > n * m - 1 - m && (u || r)) return true;
	return false;
}
 
int main(){
	memset(rig,false,sizeof(rig));
	memset(lef,false,sizeof(lef));
	memset(up,false,sizeof(up));
	memset(down,false,sizeof(down));
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++){
		scanf("%s",&ch);
		for (int j = 0; j < m; j++)
		 mp[i * m + j] = (ch[j] == '.');
	} 
	if (!check()) { printf("0\n"); return 0; }
	else if (n == 1 || m == 1) { printf("1\n"); return 0; }
	else{
		for (int i = 0; i < n; i++)
		 for (int j = 0; j < m; j++)
		  if (!vis[i * m + j]) mp[i * m + j] = 0;
		for (int i = 1; i < n; i++) if (mp[i * m] == 0) dfsr(i , 0);
		for (int i = 0; i < n - 1; i++) if (mp[(i + 1) * m - 1] == 0) dfsl(i , m - 1);
		for (int i = 1; i < m; i++) if (mp[i] == 0) dfsd(0 , i);
		for (int i = 0; i < m - 1; i++)
		 if (mp[(n - 1) * m + i] == 0) dfsu(n - 1, i);
		lef[0] = rig[0] = up[0] = down[0] = false;
		lef[n * m - 1] = rig[n * m - 1] = up[n * m - 1] = down[n * m - 1] = false;
		for (int i = 0; i < n; i++)
		 for (int j = 0; j < m; j++)
		  if (i * m + j != 0 && i * m + j != n * m -1)
		   if (mp[i * m + j] == 1 && judge(i , j)) { printf("1\n"); return 0; }
	}
	printf("2\n");
	return 0;
} 

