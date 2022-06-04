#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int str,in,exp;
		scanf("%d %d %d",&str,&in,&exp);
		int x;
		if (in + exp - str < 0) x = 0;
		else x = (in + exp - str) / 2 + 1;
		printf("%d\n" , max(exp - x + 1 , 0));
	}
}

