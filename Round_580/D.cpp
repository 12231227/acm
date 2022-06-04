#include <cstdio>
#include <algorithm>
#define ll long long
#include <cstring>
#include <vector>
using namespace std;
 
const int maxn = 1e5;
 
vector <int> g[maxn + 11];
ll a[maxn + 11];
ll b[maxn + 11];
int f[100],ans;
bool vis[maxn + 11];
int dis[2011][2011],mp[2011][1011];
 
int n;
int data = 100000000;
 
int floyd()
{
	int i, j, k, mina = data;
	for (k = 1; k <= n; k++){
		for (i = 1; i < k; i++)
		{
			for (j = 1; j < i; j++)
			{
				mina = min(dis[i][j] + mp[j][k] + mp[k][i], mina);
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (dis[i][j] > (dis[i][k] + dis[k][j]))
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
	if (mina < data)
		return mina;
	else
		return -1;
}
 
int main(){
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	for (int i = 1; i <= n; i++){ 
		scanf("%lld",&a[i]);
		for (int j = 0; j < 64; j++)
		 if (a[i] & (1ll << j)) f[j]++;
	} 
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	 if (a[i] != 0) { b[++cnt] = a[i]; }
	bool can = false;
	for (int i = 0; i < 64; i++)
	 if (f[i] >= 3) { can = true; break; }
	if (can) printf("3\n");
	else{
		n = cnt;
		for (int i = 1; i <= n; i++) a[i] = b[i];
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
		  mp[i][j] = mp[j][i] = dis[i][j] = dis[j][i] = 100000000;
		for (int i = 1; i <= n; i++)
		 for (int j = i + 1; j <= n; j++)
		  if (a[i] & a[j]){
		  	mp[i][j] = mp[j][i] = dis[i][j] = dis[j][i] = 1;
		  }
		ans = floyd();
		printf("%d\n",ans);
	} 
}

