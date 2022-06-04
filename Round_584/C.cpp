#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 2e5;

stack <pair<int,int> > s;

int vis[maxn + 11];
char ch[maxn + 11];

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		scanf("%s",&ch);
		for (int i = 0; i <= n; i++) vis[i] = 0;
		int o = -1;
		int ind = - 1;
		while (!s.empty()) s.pop();
		for (int i = 0; i < n; i++) { 
			int d = ch[i] - '0';
			pair<int,int> tmp = make_pair(-1,-1);
			while (!s.empty() && s.top().first > d) { 
				tmp = s.top();
				s.pop();
			}
			if (o == -1 && tmp.second != -1) { o = tmp.first; ind = tmp.second; }
			if (o == -1 || d <= o) s.push(make_pair(d,i));
		}
		if (o == -1) {
			for (int i = 0; i < n; i++) printf("1");
			printf("\n");
			continue;
		} 
		while (!s.empty()) { 
			vis[s.top().second] = 1;
			s.pop();
		} 
		bool can = true;
		int last = 0;
		for (int i = 0; i < n; i++){ 
		 if (vis[i]) continue;
		 int d = ch[i] - '0';
		 if (d < last) {can = false; break; } else last = d;
		} 
		if (!can) { printf("-\n"); continue; }
		for (int i = 0; i < n; i++) printf("%d",(vis[i] == 1) ? 1 : 2);
		printf("\n");
	}
}

