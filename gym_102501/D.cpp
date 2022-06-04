#include <bits/stdc++.h>
using namespace std;

const int lim = 1e6;
map <pair<int,int> , int> mp;
pair<int,int> dna[lim + 11];
bool can[2];
pair <int,int> make(int x) { int id = x > lim ? 1 : 0; return {id , x}; }
int ins = 0;
int now = 0;

deque <pair<int,int> > go(char ch[]) {
	int n = strlen(ch + 1);
	pair <int,int> pi; deque <pair<int,int> > q;
	for (int i = 1; i <= lim; i++) q.push_back({0 , i});
	for (int i = 1; i <= n; i++) {
		if (ch[i] == 'C') {
			pi = q.front();
			q.push_front(pi);
		}
		else if (ch[i] == 'D') q.pop_front();
		else if (ch[i] == 'L') {
			pi = q.front();
			if (pi.first == 1) {
				q.pop_front();
				q.push_front(make(dna[pi.second - lim].first));
			}
			else can[now] = false;
		}
		else if (ch[i] == 'P') {
			pair <int,int> t1,t2;
			t1 = q.front(); q.pop_front(); t2 = q.front(); q.pop_front();
			int id;
			if (!mp[{t1.second , t2.second}]) {
				mp[{t1.second , t2.second}] = ++ins;
				dna[ins] = {t1.second , t2.second};
				id = ins;
			}
			else id = mp[{t1.second , t2.second}];
			q.push_front({1 , id + lim});
		}
		else if (ch[i] == 'R') {
			pi = q.front();
			if (pi.first == 1) {
				q.pop_front();
				q.push_front(make(dna[pi.second - lim].second));
			}
			else can[now] = false;
		}
		else if (ch[i] == 'S') {
			pair <int,int> t1,t2;
			t1 = q.front(); q.pop_front(); t2 = q.front(); q.pop_front();
			q.push_front(t1); q.push_front(t2);
		}
		else if (ch[i] == 'U') {
			pi = q.front();
			if (pi.first == 1) {
				q.pop_front();
				q.push_front(make(dna[pi.second - lim].second));
				q.push_front(make(dna[pi.second - lim].first));
			}
			else can[now] = false;
		}
		if (q.size() <= 3) can[now] = false;
		if (!can[now]) return q;
	}
	return q;
}

int main(){ 
	char ch[10011];
	can[0] = can[1] = true;
	deque <pair<int,int> > d1,d2;
	scanf("%s" , ch + 1); d1 = go(ch); now++;
	scanf("%s" , ch + 1); d2 = go(ch);
	if (!can[0] && !can[1]) {
		printf("True\n");
		return 0;
	}
	else if (!(can[0] && can[1]) || d1.size() != d2.size()) {
		printf("False\n");
		return 0;
	}
	bool flag = true;
	while (!d1.empty() && !d2.empty()) {
		pair <int,int> t1,t2;
		t1 = d1.front(); t2 = d2.front(); d1.pop_front(); d2.pop_front();
		if (t1 == t2) continue;
		flag = false; break;
	}
	if (flag) printf("True\n");
	else printf("False\n");
} 

