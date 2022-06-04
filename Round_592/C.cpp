// #include<bits/stdc++.h>
// void scan(__int128 &x)
// {
//     x = 0;
//     int f = 1;
//     char ch;
//     if((ch = getchar()) == '-') f = -f;
//     else x = x*10 + ch-'0';
//     while((ch = getchar()) >= '0' && ch <= '9')
//         x = x*10 + ch-'0';
//     x *= f;
// }

// void _print(__int128 x) 
// {
//     if(x > 9) _print(x/10);
//     putchar(x%10 + '0');
// }

// __int128 exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y){
// 	if(b==0) {
// 		x=1,y=0;
// 		return a;
// 	}
// 	__int128 t=exgcd(b,a%b,x,y); 
// 	__int128 x0=x,y0=y;
// 	x=y0;
// 	y=x0-(a/b)*y0;
// 	return t;
// }

 

// int main(){
//     __int128 a,x,y,b,c,n;
//     scan(n);
//     scan(c);
//     scan(a);
//     scan(b);
//     __int128 t=exgcd(a,b,x,y);
// 	if(c%t!=0) printf("-1\n");
//     else{
// 	   	x = x * c / t;
//     	y = (c - a * x) / b;
//     	__int128 k1,k2,k3;
//     	k1 = -x * t / b;
//     	if ((x * t) % b != 0 && x < 0)  k1++;
//     	k2 = y * t / a;
//     	if ((y * t) % a != 0 && y < 0) k2--;
//     	k3 = ((n  - x - y) * t) / (b - a);
//     	if (((n  - x - y) * t) % (b - a) != 0 && (n - x - y < 0)) k3++;
//     	__int128 k;
//     	if (k1 >= k3) k = k1; else k = k3;
//     	x = x + k * b / t;
//     	y = y - k * a / t;
//     	if (k2 < k) printf("-1\n");
//     	else {
//     		_print(x); printf(" "); _print(y); printf(" "); _print(n - x - y); printf("\n");
// 		}
// 	}
// 	return 0;
// }
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b) { return b == 0 ? a : gcd(b , a % b); }

int main(){
    ll n,p,w,d;
    cin >> n >> p >> w >> d;
    ll t = d / gcd(w , d);
    ll x = -1;
    for (ll i = 0; i < t; i++)
        if ((p - i * w) % d == 0) { x = i; break; }
    if (x == -1) { printf("-1\n"); return 0; }
    ll y = (p - x * w) / d;
    if (y < 0) { printf("-1\n"); return 0; }
    ll k = min((n - x) * gcd(w , d) / d , (y * gcd(w , d) / w));
    x += k * t;
    y = (p - x * w) / d;
    if (x >= 0 && y >= 0 && n - x - y >= 0) { printf("%lld %lld %lld\n" , x , y , n - x - y); return 0; }
    printf("-1\n");
} 

