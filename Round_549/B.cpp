#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n){
	if (n==0) return 1;
	if (n<10) return n;
	return max(solve(n / 10)*(n % 10),solve(n / 10 -1) * 9);
}

int main(){
	int n;
	cin >> n;
	printf("%d\n",solve(n));
}

