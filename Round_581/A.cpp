#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char ch[110];
	scanf("%s",&ch);
	int n = strlen(ch);
	int x,y;
	x = y = n;
	for (int i = 0; i < n; i++)
	 if (ch[i] == '1') {
	 	if (x == n) x = i;
	 	else if (y == n) y = i;
	 	else break;
	 }
	if (x == n) printf("0\n");
	else{
		if (y == n) {
			if ((n -1 - x) % 2 == 0) printf("%d\n",(n  - 1 -  x) / 2);
			else printf("%d\n",(n - 1 - x) / 2 + 1);
		}
		else printf("%d\n",(n - 1 - x) / 2 + 1);
	}
} 

