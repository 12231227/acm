#include <cstdio>
using namespace std;

const int maxn = 200000;

char ch[maxn + 11];

int main(){ 
	int n;
	scanf("%d",&n);
	scanf("%s",ch);
	if (n % 2 == 1) printf("No\n");
	else{
		int num = 0;
		bool can = true;
		for (int i = 0; i < n; i++) {
			if (ch[i] == '(') num++; else num--;
			if (num < -1) { can = false; break; }
		}
		if (num == 0 && can) printf("Yes\n");
		else printf("No\n");
	}
} 

