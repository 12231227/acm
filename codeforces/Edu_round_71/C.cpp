#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int maxn = 2e5;
ll f[maxn + 11][2];

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		memset(f,0x3f3f3f3f,sizeof(f));
		int n;
		ll a,b;
		scanf("%d %lld %lld",&n,&a,&b);
		char ch[maxn + 11];
		scanf("%s",ch);
		f[0][0] = b;
		for (int i = 1; i < n; i++){
			if (ch[i - 1] == '0' && ch[i] == '0'){
				f[i][0] = min(f[i - 1][0] + a + b , f[i - 1][1] + b + 2 * a);
				f[i][1] = min(f[i - 1][0] + 2 * b + 2 * a , f[i - 1][1] + a + 2 * b);
			}
			else{
				f[i][1] = min(f[i - 1][0] + 2 * b + 2 * a , f[i - 1][1] + a + 2 * b);
			}
		}
		ll ans = min(f[n - 1][0] + a + b , f[n - 1][1] + b + 2 * a);
		printf("%lld\n",ans);
	}
}

