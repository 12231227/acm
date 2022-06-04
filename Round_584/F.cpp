    #include <bits/stdc++.h>
    #define all(x) (x).begin(),(x).end()
    #define ll long long
    #define int long long
    using namespace std;
     
    const int maxn = 1e6;
    const ll mol = 1e9 + 7;
     
    bool vis[2 * maxn + 11] = {false};
    ll ans[2 * maxn + 11];
    vector <int> edge[2 * maxn + 11][10];
    vector <int> tmp;
     
    signed main(){
    	//freopen("in.txt","r",stdin);
    	int n,m;
    	scanf("%lld %lld",&n,&m);
    	int tot = n;
    	for (int i = 1; i <= m; i++) { 
    		tmp.clear();
    		int u,v;
    		scanf("%lld %lld",&u,&v);
    		int val = i;
    		while (val) { tmp.push_back(val % 10); val /= 10; }
    		reverse(all(tmp));
    		int pre = u;
    		for (int j = 0; j < tmp.size(); j++){
    			int x = (j + 1 == tmp.size()) ? v : ++tot;
    			edge[pre][tmp[j]].push_back(x);
    			pre = x;
    		}
    		pre = v;
    		for (int j = 0; j < tmp.size(); j++){ 
    			int x = (j + 1 == tmp.size()) ? u : ++tot;
    			edge[pre][tmp[j]].push_back(x);
    			pre = x;
    		} 
    	} 
    	queue< vector <int> > q;
    	q.push({1});
    	vis[1] = true;
    	vector <int> tmp;
    	while (!q.empty()) {
    		vector <int> v = q.front(); q.pop();
    		
    		for (int j = 0; j < 10; j++){
    			tmp.clear();
	    		for (auto u : v)
	    				for (auto p : edge[u][j]) { 
	    					if (vis[p]) continue;
	    					vis[p] = true;
	    					tmp.push_back(p);
	    					ans[p] = (ans[u] * 10 + j) % mol;
	    				}
	    		if (tmp.size()) q.push(tmp);
	    	}
    	}
    	for (int i = 2; i <= n; i++) printf("%lld\n" , ans[i]);
    } 
 