#include <bits/stdc++.h>
using namespace std;

int a[1111];

int main(){
	for (int i = 1; i <= 100; i++) a[i] = i;
	int ind = lower_bound(a + 1 , a + 50 , 30) - a;
	cout << ind;
}
