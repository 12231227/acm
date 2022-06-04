#include <cstdio>
#define ll long long
using namespace std;

ll f[710][710];
ll a[500011];

int main(){
	int q;
	scanf("%d",&q);
	while (q--){
		int t,x,y;
		scanf("%d %d %d",&t,&x,&y);
		if (t == 1){
			for (int i = 1; i <= 700; i++)
			 f[i][x % i] = f[i][x % i] + y;
			a[x] += y;
		}
		else{
			if (x <= 700) printf("%lld\n",f[x][y]);
			else{
				ll ans = 0;
				for (int i = y;i <= 500000 ; i += x) ans += a[i];
				 printf("%lld\n",ans);
			}
		}
	}
}

