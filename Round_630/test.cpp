#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;
int t;
int n,k;
const int maxn = 2e5+100;
char s[maxn];
int cnt[maxn][150];
int main()
{
   scanf("%d",&t);
   while(t--){
   	scanf("%d%d",&n,&k);
   	for(int i = 1;i<=k;i++){
   		for(int j = 'a';j<='z';j++){
   			cnt[i][j] = 0;
   		}
   	}
   	scanf("%s",s+1);
   	int gnum = n/k;
   	for(int i = 0;i<gnum;i++){
   		for(int j = 1;j<=k;j++){
   			int tmp = s[i*k+j];
   			cnt[j][tmp] += 1;
   		}
   	}
   	int res = 0;
   	for(int i = 1;i<=k/2;i++){
   		int maxx = 0;
   		for(int j = 'a';j<='z';j++){
   			maxx = max(maxx,cnt[i][j]+cnt[k-i+1][j]);
   		}
   		res += gnum*2-maxx;
   	}
   	if(k&1){
   		int mid = k/2+1;
   		int maxx = 0;
   		for(int j = 'a';j<='z';j++){
   			maxx = max(maxx,cnt[mid][j]);
   		}
   		res += gnum-maxx;
   	}
   	printf("%d\n",res);

   }






    return 0;
}