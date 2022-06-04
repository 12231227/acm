#include <bits/stdc++.h>
using namespace std;

int a[10];

int main(){ 
	int sum = 0;
	for (int i = 1;i <= 4; i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	bool can = false;
	for (int i = 1; i <= 4; i++) 
	 for (int j = 1; j <= 4; j++) 
	  if (i != j && (a[i] + a[j]) * 2 == sum) can = true;
	for (int i = 1; i <= 4; i++)
	 if (a[i] * 2 == sum) can = true;
	if (can) printf("YES\n");
	else printf("NO\n");
} 

