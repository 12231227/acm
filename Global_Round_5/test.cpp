#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
 
using namespace std;
 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
typedef long long ll;
#define MOD 998244353ll
	
int D,N,M;
 
int pos;
int a[2000010];
 
ll main2(void){
	int cnt = 0;
	int i;
	
	for(i=1;i<M;i+=2){
		if(cnt % 2 == a[i]){
			cnt++;
		} else if(cnt % 2 == a[i-1]){
			cnt += 2;
		} else {
			return 0;
		}
	}
	
	if(cnt < N && cnt % 2 == a[M-1]) cnt++;
	
	return ((cnt == N) ? 1 : 0);
}
 
void dfs(int d, int val){
	if(d < D) dfs(d+1, (val^1));
	a[pos] = val;
	pos++;
	if(d < D) dfs(d+1, val);
}
 
int main(void){
	int i;
	
	cin >> N;
	
	M = 1;
	while(M < N){
		M = 2 * M + 1;
		D++;
	}
	
	dfs(0, 0);
	
	ll ans = main2();
	REP(i,M) a[i] ^= 1;
	ans += main2();
	ans %= MOD;
	
	cout << ans << endl;
	
	return 0;
}

