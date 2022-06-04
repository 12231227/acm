#include <bits/stdc++.h>

const int maxn = 2e5;
int a[maxn + 11],b[maxn + 11],c[maxn + 11],p[maxn + 11],g[maxn + 11];

using namespace std;
int main(){
	int k1,k2,k3;
	scanf("%d %d %d",&k1,&k2,&k3);
	for (int i = 1; i <= k1; i++) scanf("%d",&a[i]); sort(a + 1 , a + 1 + k1);
	for (int i = 1; i <= k2; i++) scanf("%d",&b[i]); sort(b + 1 , b + 1 + k2);
	for (int i = 1; i <= k3; i++) scanf("%d",&c[i]); sort(c + 1 , c + 1 + k3);
	int n = k1 + k2 + k3;
	for (int i = 1; i <= k1; i++) p[i] = a[i];
	for (int i = 1; i <= k2; i++)
	 p[i + k1] = b[i];
	for (int i = 1; i <= k3; i++) p[i + k1 + k2] = c[i];
	int len = 1;
	g[1] = p[1];
	for(int i=2;i<=n;i++)
	{
   	 if(p[i]>g[len]){
   	     g[++len]=p[i];
    }
    else{
       	    int ind=lower_bound(g+1,g+len+1,p[i])-g;
        	g[ind]=p[i];
   		}
	}
	len = n - len;
	int res = max(k1 , k2);
	res = max(res , k3);
	res = n - res;
	int ans = min(res , len);
	printf("%d\n" , ans);
} 

