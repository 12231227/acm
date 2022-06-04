#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5e5;

int main(){
	int q;
	scanf("%d",&q);
	while (q--){
		int n,m;
		scanf("%d %d",&n,&m);
		int cow = 0; int numcow = 0;
		int cul = 0; int numcul = 0;
		char st[maxn];
		for (int i = 1; i <= n; i++) {
			char ch[maxn];
			scanf("%s",ch);
			for (int j = 0 ; j < m; j++) st[(i - 1) * m + j] = ch[j];
		}
		bool visi[maxn];
		memset(visi,false,sizeof(visi));
		for (int i = 0; i < n; i++){
			int x = 0;
			for (int j = 0; j < m; j++)
			 if (st[i * m + j] == '*') x++;
			if (x > cow) { cow = x; numcow = i; }
		}
		for (int i = 0; i < n; i++){
			int x = 0;
			for (int j = 0; j < m; j++)
			 if (st[i * m + j] == '*') x++;
			if (x == cow) visi[i] = true;
		}
		bool visj[maxn];
		memset(visj,false,sizeof(visj));
		for (int i = 0; i < m; i++){
			int x = 0;
			for (int j = 0; j < n; j++)
			 if (st[j * m + i] == '*') x++;
			if (x > cul) { cul = x; numcul = i; }
		}
		for (int i = 0; i < m; i++){
			int x = 0;
			for (int j = 0; j < n; j++)
			 if (st[j * m + i] == '*') x++;
			if (x == cul) visj[i] = true;
		}
		int ans = n + m - cul - cow;
		int tmp = 1;
		for (int i = 0; i < n; i++)
		 for (int j = 0; j < m; j++)
		  if (visi[i] && visj[j] && st[i * m + j] == '.') {ans-=tmp; tmp = 0; break;}
		printf("%d\n",ans);
	}
} 
