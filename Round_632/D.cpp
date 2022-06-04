#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxt = 3000000;
const int maxn = 3000;
int n,k;

char ch[maxn + 11];
struct node{
	int l,r,p;
	bool operator < (const node &rh) const {
		if (l != rh.l) return l < rh.l;
		if (r != rh.r) return r < rh.r;
		return p < rh.p;
	}
};

vector <node> tim;
vector <int> ans[maxt + 11];

bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (ch[i] == 'L') cnt++;
	return cnt == 0 || cnt == n;
}

int main(){
	scanf("%d %d" , &n,&k);
	scanf("%s" , ch + 1);
	if (check()) { puts("-1"); return 0; }
	int mx = 0;
	int has = 0;
	int pos = 0;
	int fp = 0;
	int ob = 0;
	for (int i = n; i >= 1; i--)
		if (ch[i] == 'L') { pos = i; break; }
	for (int i = 1; i < pos; i++) {
		if (ch[i] == 'R') continue;
		has++;
		int st = 1;
		if (fp && ob - i + fp + 2 > st) st = ob - i + fp + 2;
		int ti = i - has + st - 1;
		mx = max(mx , ti);
		if (ti >= st) { 
			tim.pb(node{st , ti , i - 1});
		}
		ob = st;
		fp = i;
	}
	has++;
	int st = 1;
	if (fp && ob - pos + fp + 2 > st) st = ob - pos + fp + 2;
	int ti = pos - has + st - 1;
	if (ti >= st) tim.pb(node{st , ti , pos - 1});
	mx = max(mx , ti);
	if (mx > k) { puts("-1"); return 0; }
	sort(tim.begin() , tim.end());
	int sum = 0;
	for (auto pi : tim) sum += pi.r - pi.l + 1;
	if (sum < k)  { puts("-1"); return 0; }
	int L = 0 , R = -1 , T = 0 , Ti = 0;
	while (1) {
		T++;
		while (R + 1 < tim.size() && tim[R + 1].l == T) R++;
		int _ = -1;
		for (int i = L; i <= R; i++) {
			if (++Ti == k + T - mx) { _ = i; break; }
			printf("1 %d\n" , tim[i].p--);
			tim[i].l++;
		}
		if (_ != -1) {
			printf("%d" , R - _ + 1);
			for (int i = _; i <= R; i++)
				printf(" %d" , tim[i].p--);
			puts("");
		}
		while ()
	}
} 
