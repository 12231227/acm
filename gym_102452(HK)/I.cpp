#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;

struct node{
	ll goal; int id,v;
	bool operator < (const node &rh) const {
		return goal > rh.goal;
	}
};

struct node2{
	int y;
	vector <int> ob;
	vector <ll> last_goal;
}per[maxn + 11];

priority_queue <node> ob[maxn + 11];

ll sum[maxn + 11];
vector <int> ans;
int vis[maxn + 11];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int last = 0;
	int id = 0;
	while (m--) {
		int op;
		scanf("%d" , &op);
		if (op == 1) {
			int y,k;
			scanf("%d %d",&y,&k);
			y ^= last;
			per[++id].y = y;
			int ave = (y + 2) / 3;
			for (int i = 1; i <= k; i++) { 
				int q;
				scanf("%d",&q); q ^= last;
				per[id].ob.push_back(q);
				per[id].last_goal.push_back(sum[q]);
				ob[q].push({sum[q] + ave , id , 0});
			} 
		} 
		else { 
			int x,y;
			scanf("%d %d",&x,&y); x ^= last; y ^= last;
			ans.clear();
			sum[x] += y;
			while (!ob[x].empty() && sum[x] >= ob[x].top().goal) { 
				auto pi = ob[x].top(); ob[x].pop();
				if (pi.v != vis[pi.id]) continue;
				vis[pi.id]++;
				int sub = 0;
				for (int i = 0; i < per[pi.id].ob.size(); i++) sub += sum[per[pi.id].ob[i]] - per[pi.id].last_goal[i];
				per[pi.id].y -= sub;
				if (per[pi.id].y <= 0) { ans.push_back(pi.id); continue; }
				int ave = (per[pi.id].y + 2) / 3;
				for (int i = 0; i < per[pi.id].ob.size(); i++) {
					int u = per[pi.id].ob[i];
					per[pi.id].last_goal[i] = sum[u];
					ob[u].push({sum[u] + ave , pi.id , vis[pi.id]});
				}
			}
			last = ans.size();
			printf("%d%s" , last , last == 0 ? "\n" : " ");
			if (ans.size()) sort(ans.begin() , ans.end());
			for (int i = 0; i < last; i++) printf("%d%s",ans[i] , i + 1 == last ? "\n" : " ");
		}
	}
}
