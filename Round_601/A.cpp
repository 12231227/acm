#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int a,b;
		scanf("%d %d",&a,&b);
		if (a > b) swap(a , b);
		int num1 = (b - a) / 5;
		b -= num1 * 5;
		int num2 = (b - a) / 2;
		b -= num2 * 2;
		int num3 = b - a;
		printf("%d\n" ,num1 + num2 + num3);
	}
}

