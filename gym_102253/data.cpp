
#include<bits/stdc++.h>

using namespace std;

int n,m,cnt,fa[100015];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int find(int x){

	return x==fa[x]?x:fa[x]=find(fa[x]);

}

int main()

{
	freopen("1.in","w",stdout);
	n=rng()%10+1;
	m=rng()%(n-1)+1;
	int q=  rng()%10+1;
	cout << n << " " << m << " " << q<< endl;
	int two[55]; two[0] = 1;
	for (int i = 1; i <= 30; i++) two[i] = two[i - 1] * 2;
	for (int i = 1; i <= n; i++) {
		int x = rng() % 31;
		cout << two[x] << endl;
	}
	for(int i=1;i<=n;i++)fa[i]=i;

	while(cnt<m){

		int x=rng()%n+1,y=rng()%n+1;

		int x1=find(x),y1=find(y);

		if(x1!=y1){
			fa[x1]=y1,cnt++;
			int op = rng() % 2 + 1;
			cout << op << " " << x << " " << y << endl;
		}

	}
	while (q--) {
		int op = rng()% 2 + 1;
		int x = rng()%n+1;
		int y = rng()%31;
		cout << op << " " << x << " " << two[y] << endl;

	}
}	
