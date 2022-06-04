#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

int inputs[100005];
int leftjump[100005];
int rightjump[100005];
int ans[100005];

pair<int, int> pos[100005];

stack<int> bigger, smaller;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inputs[i];
		pos[i] = make_pair(inputs[i], i);
	}
	inputs[0] = inputs[n + 1] = 1e9 + 10;
	smaller.push(0);
	for (int i = 1; i <= n; i++) {
		int last = 0;
		while (inputs[smaller.top()] <= inputs[i]) {
			last = smaller.top();
			smaller.pop();
		}
		leftjump[i] = smaller.top();
		if (inputs[last] == inputs[i])
			smaller.push(last);
		else
			smaller.push(i);
	}
	bigger.push(n + 1);
	for (int i = n; i >= 1; i--) {
		int last = n + 1;
		while (inputs[bigger.top()] <= inputs[i]) {
			last = bigger.top();
			bigger.pop();
		}
		rightjump[i] = bigger.top();
		if (inputs[last] == inputs[i])
			bigger.push(last);
		else
			bigger.push(i);
	}
	sort(pos + 1, pos + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (pos[i].first == pos[n].first)
			ans[pos[i].second] = 0;
		else {
			if (leftjump[pos[i].second] != 0)
				ans[pos[i].second] = max(ans[leftjump[pos[i].second]] + pos[i].second - leftjump[pos[i].second], ans[pos[i].second]);
			if (rightjump[pos[i].second] != n + 1)
				ans[pos[i].second] = max(ans[pos[i].second], ans[rightjump[pos[i].second]] - pos[i].second + rightjump[pos[i].second]);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	//system("pause");
	return 0;
}