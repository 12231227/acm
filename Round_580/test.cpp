#include <cstdio>
#include <algorithm>
#define ll long long
#include <cstring>
#include <vector>
using namespace std;
 
const int maxn = 1e5;
 
vector <int> g[10100];
ll a[maxn + 11];
int f[100],ans;
bool vis[maxn + 11];
int dis[1011][1011],mp[1011][1011];
int d[maxn +11];
 
//void dfs(int x,int fa){
//	d[x] = d[fa] + 1;
//	vis[x] = true;
//	for (int i = 0; i < g[x].size(); i++){
//		if (g[x][i] == fa) continue;
//		int v = g[x][i];
//		if (d[v] >= d[x]) { dfs(v , x); continue; }
//		if (vis[v]) ans = min(ans , d[x] - d[v] + 1);
//		else dfs(v , x);
//	}
//}
 
int n;
 
int Floyd_MinCircle()
{
    int Mincircle = 1000000;
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dis[i][j] != 1000000 && mp[j][k] != 1000000 && mp[k][i] != 1000000 && dis[i][j] + mp[j][k] + mp[k][i] < Mincircle)
                    Mincircle = dis[i][j] + mp[j][k] + mp[k][i];
            }
        }
        //Õý³£Floyd
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dis[i][k] != 1000000 && dis[k][j] != 1000000 && dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    return Mincircle;
}
 
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		for (int j = 0; j < 64; j++)
		 if (a[i] & (1 << j)) f[j]++;
	}
	bool can = false;
	for (int i = 0; i < 64; i++)
	 if (f[i] >= 3) { can = true; break; }
	if (can) printf("3\n");
	else{
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++) 
		  mp[i][j] = mp[j][i] = dis[i][j] = dis[j][i] = 1000000;
		for (int i = 1; i <= n; i++)
		 for (int j = i + 1; j <= n; j++)
		  if (a[i] & a[j]){
		  	mp[i][j] = mp[j][i] = dis[i][j] = dis[j][i] = 1;
		  }
		ans = Floyd_MinCircle();
		if (ans == 1000000) printf("-1\n");
		else printf("%d\n",ans);
	} 
}

