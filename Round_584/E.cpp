#include <bits/stdc++.h>
using namespace std;

vector <int> v[5000];
int f[5000][5000],pre[5000][5000];
int calc(int ind,int state,int n) { 
	int ans = 0;
	for (int i = 0; i < n; i++){ 
	 int res = 0;
	 for (int j = 0; j <= n; j++) 
	  if ((1 << j) & state) res += v[ind][(i + j) % n];
	 ans = max(ans , res);
	} 
	return ans;
}

bool cmp(vector <int> a, vector <int> b) {
	int ansa = 0;
	for (int i = 0; i < a.size(); i++) ansa = max(ansa , a[i]);
	int ansb = 0;
	for (int i = 0; i < b.size(); i++) ansb = max(ansb , b[i]);
	return ansa > ansb;
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,m;
		scanf("%d %d",&n,&m);
		for (int i = 1; i <= n; i++) 
		 for (int j = 1; j <= m; j++) {
		 	int x;
		 	scanf("%d",&x);
		 	v[j].push_back(x);
		 }
		sort(v + 1, v + 1 + m , cmp);
		int s = (1 << n) - 1;
		for (int i = 1; i <= min(n,m); i++)
		 for (int j = 0;j <= s; j++) pre[i][j] = calc(i , j , n);
		for (int i = 1; i <= min(n , m); i++) 
		 for (int j = 0; j <= s; j++){ 
		  f[i][j] = pre[i][j];
		  for (int k = j; k ; k = (k - 1) & j) { 
		  	f[i][j] = max(f[i][j] , f[i - 1][k] + pre[i][j ^ k]);
		  }
		}
		printf("%d\n" , f[min(n , m)][s]);
		for (int i = 1; i <= m; i++) v[i].clear();
		for (int i = 1; i <= min(n , m); i++)
		 for (int j = 0; j <= s; j++) f[i][j] = 0;
	}
} 

