#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5e5;

char ch[maxn + 11];
int main(){
	scanf("%s",&ch);
	int n = strlen(ch);
	char m = 'z';
	for (int i = 0; i < n; i++) {
		if (i == 0 || m >= ch[i]) printf("Mike\n");
		else printf("Ann\n");
		if (ch[i] < m) m = ch[i];
	}
}

