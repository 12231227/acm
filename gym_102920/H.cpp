#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
const double Pi=acos(-1.0);
const int mol = 1e9 + 7;
const int maxn = 60000 * 5;

struct cp{
    double x,y;
    cp friend operator + (cp a,cp b)
    {
        return (cp){a.x+b.x,a.y+b.y};
    }
    cp friend operator - (cp a,cp b)
    {
        return (cp){a.x-b.x,a.y-b.y};
    }
    cp friend operator * (cp a,cp b)
    {
        return (cp){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
    }
}A[maxn],B[maxn];
int R[maxn];
long long ans[maxn];
int a[maxn],b[maxn],c[maxn];
int lim,n,m;
int l;
void FFt(cp *l,double f)
{
    for(int i=0;i<lim;i++)
        if(i<R[i])
            std::swap(l[i],l[R[i]]);
    for(int i=1;i<lim;i<<=1)
    {
        cp Wn;
        Wn=(cp){cos(Pi/i),f*sin(Pi/i)};
        for(int j=0;j<lim;j+=(i<<1))
        {
            cp W;
            W=(cp){1.00,0.00};
            for(int k=0;k<i;k++,W=W*Wn)
            {
                cp nx,ny;
                nx=l[j+k];
                ny=l[i+j+k]*W;
                l[j+k]=nx+ny;
                l[i+j+k]=nx-ny;
            }
        }
    }
}

int main()
{
	int N; scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d",&x); x += 30000;
		a[x]++;
	}
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d",&x); x += 30000;
		b[x]++;
	}
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d",&x); x += 30000;
		c[x]++;
	}
    l=0;
    lim=1;
    n = m = 60000;
    for(int i=0;i<=n;i++)
    {
    	A[i].x = a[i];
    }
    for(int i=0;i<=m;i++)
    {
        B[i].x = c[i];
    }
    while(lim<=(n+m))
    {
        lim=lim<<1;
        l++;
    }
    for(int i=0;i<lim;i++)
    {
        R[i]=(R[i>>1]>>1)|((i&1)<<(l-1));
    }
    FFt(A,1.00);
    FFt(B,1.00);
    for(int i=0;i<=lim;i++)
    {
        A[i]=A[i]*B[i];
    }
    FFt(A,-1.00);
    for(int i=0;i<=n+m;i++)
    	ans[i] = (long long)(A[i].x / lim + 0.5);
    long long cnt = 0;
    for (int i = 0; i <= 60000; i++)
    	cnt += 1ll * ans[2 * i] * b[i];
   	printf("%lld\n" , cnt);
    return 0;
}
