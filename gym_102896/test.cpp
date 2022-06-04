#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
list<int>p[21];int f[21];
int main(){int n;
	scanf("%d",&n);
	rep(i,2,n)scanf("%d",&f[i]);
	dep(i,n,2){
		p[i].push_front(i);
		list<int>res(p[f[i]]);int t=1;
		for(auto&j:p[i]){
			res.push_back(j);
			if(t&1)for(auto k=p[f[i]].rbegin();k!=p[f[i]].rend();++k)res.push_back(*k);
			else for(auto k=p[f[i]].begin();k!=p[f[i]].end();++k)res.push_back(*k);
			t^=1;
		}
		res.swap(p[f[i]]);
	}
	printf("%d\n",(int)p[1].size());
	for(auto&i:p[1])printf("%d ",i);
}
