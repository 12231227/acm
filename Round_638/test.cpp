#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define FI first
#define SE second
#define ULL unsigned long long
#define endl '\n'
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-8;
const int maxn=1<<17;
const int N=1e6+7,M=1<<16,mod=1e9+7;
int n,m;
struct node{
    int l,r;
    int id;
    bool operator<(const node&x)const{
        if(l==x.l)return r<x.r;
        return l<x.l;
    }
}a[N];
struct nd{
    int r,id;
    bool operator<(const nd &x)const{
        return r>x.r;
    }
};
int l[N],r[N];
int pos[N];
int ans[N];
vector<int>v[N],w[N];
int s[N],flag[N];
void update(int a,int b,int x,int k,int l,int r){
    if(a==l&&b==r){
        s[x]=max(s[x],k);
        flag[x]=max(flag[x],k);
        return;
    }
    int mid=l+r>>1,ls=x<<1,rs=x<<1|1;
    if(flag[x]){
        update(l,mid,ls,flag[x],l,mid);
        update(mid+1,r,rs,flag[x],mid+1,r);
        flag[x]=0;
    }
    if(b<=mid)update(a,b,ls,k,l,mid);
    else if(a>mid)update(a,b,rs,k,mid+1,r);
    else{
        update(a,mid,ls,k,l,mid);
        update(mid+1,b,rs,k,mid+1,r);
    }
    s[x]=max(s[ls],s[rs]);
}
int query(int loc,int x,int l,int r){
    if(l==r)return s[x];
    int mid=l+r>>1,ls=x<<1,rs=x<<1|1;
    if(flag[x]){
        update(l,mid,ls,flag[x],l,mid);
        update(mid+1,r,rs,flag[x],mid+1,r);
        flag[x]=0;
    }
    if(loc<=mid)return query(loc,ls,l,mid);
    else return query(loc,rs,mid+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i;
        l[i]=a[i].l,r[i]=a[i].r;
    }
    sort(a+1,a+1+n);
    int now=1;
    priority_queue<nd>q;
    for(int i=1;i<=n;i++){
        while(a[now].l<=i&&now<=n){
            q.push(nd{a[now].r,a[now].id});
            now++;
        }
        nd x=q.top();
        q.pop();
        ans[x.id]=i;
        pos[i]=x.id;
    }
    int flag=0,f=0;
    for(int i=1;i<=n;i++){
        int x=pos[i];
        //cout<<i<<' '<<x<<' '<<l[x]<<endl;
        int y=query(i,1,1,n);
        if(l[x]<=y){
            flag=x,f=pos[y];
            break;
        }
        update(i,r[x],1,i,1,n);
    }

    if(flag==0){
        printf("YES\n");
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    }
    else{
        printf("NO\n");
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);printf("\n");
        swap(ans[flag],ans[f]);
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    }
    return 0;
}
/*
5
1 5
2 2
3 3
4 4
1 5
*/

