#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2e5;

char str[maxn + 11][20];

void gz(int ind){
	int x = ind - 1;
	for (int i = 0; i < ind; i++){
	 if ((1 << i) > ind) {
	 	break;
	 }
	 str[x][i] = (ind & (1 << i)) == 0 ? '0' : '1';
	}
}

int find(int x) {
	for (int i = 0; ; i++)
	 if ((1 << i) > x) return i - 1;
}

int main(){
	for (int i = 1; i <= maxn; i++)
	 gz(i);
	int t;
	scanf("%d",&t);
	while (t--){
		long long ans = 0;
		char ch[maxn + 11];
		scanf("%s",ch);
		int n = strlen(ch);
		int now = 0;
		for (int i = 0; i < n; i++){
			if (ch[i] == '0') { now++; continue; }
			ans++;
			int tmp = 1;
			for (int j = i + 1;j < n; j++){
			 tmp = (tmp << 1) + (ch[j] == '1');
			 if (now + j - i + 1 >= tmp) ans++; else break;
			 if (tmp > maxn) break;
			}
			now = 0;
		}
		printf("%lld\n",ans);
	}
}

