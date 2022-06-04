#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0) {
		x=1,y=0;
		return a;
	}
	ll t=exgcd(b,a%b,x,y); 
	ll x0=x,y0=y;
	x=y0;
	y=x0-(a/b)*y0;
	return t;
}
 
int main(){
    ll a,x,y,b,c,n; 
    cin >> n >> c >> a >> b;
    int t=exgcd(a,b,x,y);
	if(c%t!=0) printf("-1\n");
    else{
    	x = x * c / t;
    	y = y * c / t;
    	ll k1,k2,k3;
    	k1 = -x * t / b;
    	if ((x * t) % b != 0 && x < 0)  k1++;
    	k2 = y * t / a;
    	if ((y * t) % a != 0 && y < 0) k2--;
    	k3 = ((n  - x - y) * t) / (b - a);
    	if (((n  - x - y) * t) % (b - a) != 0 && (n - x - y < 0)) k3++;
    	ll k = max(k1 , k3);
    	x = x + k * b / t;
    	y = y - k * a / t;
    	if (k2 < k) printf("-1\n");
    	else printf("%lld %lld %lld\n" , x , y , n - x - y);
	}
	return 0;
}
