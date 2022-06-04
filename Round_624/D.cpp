#include <bits/stdc++.h>
using namespace std;

const int n = 2e4;
vector <int> d[n + 11];

int main(){
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			d[j].emplace_back(i);
	int t;
	scanf("%d" , &t);
	while (t--) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int ans = 10 * n;
		int A,B,C;
		for (int i = n; i >= 1; i--) {
			for (auto j : d[i])
				for (auto k : d[j]){
					if (abs(i - c) + abs(j - b) + abs(k - a) < ans) {
						ans = abs(i - c) + abs(j - b) + abs(k - a);
						A = k; B = j; C = i;
					}
				}
		}
		printf("%d\n" , ans);
		printf("%d %d %d\n" , A , B , C);
	}
} 
