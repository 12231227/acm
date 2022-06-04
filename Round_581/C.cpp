#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e6;
 
int a[111][111];
int b[maxn + 11];
vector<int>v;
 
 
 
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
	 char ch[111];
	 scanf("%s",&ch);
	 for (int j = 0; j < n; j++)
	  if (ch[j] == '0') a[i][j + 1] = 1000000; else a[i][j + 1] = 1;
	}
	for (int k = 1; k <= n; k++)
	 for (int i = 1; i <= n; i++)
	 if (i != k)
	  for (int j = 1; j <= n; j++)
	   if (i != j && k != j)
	    if (a[i][k] + a[k][j] < a[i][j]) a[i][j] = a[i][k] + a[k][j];
	int m;
	scanf("%d",&m);
	for (int i = 1; i <= m; i++) scanf("%d",&b[i]);
	v.push_back(b[1]);
	int last = b[1];
	for (int i = 2; i < m; i++){
	 if (a[last][b[i]] + a[b[i]][b[i + 1]] == a[last][b[i + 1]]) continue;
	 v.push_back(b[i]);
	 last = b[i];
	}
	v.push_back(b[m]);
	printf("%d\n",v.size());
	for (int i = 0; i < v.size(); i++) printf("%d%s",v[i], i + 1 == v.size() ? "\n" : " ");
} 

