#include <cstdio>
#include <cstring>
using namespace std;

char ch[100005];
int main(){
	scanf("%s",ch);
	int n = strlen(ch);
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--){
		if (ch[i] == '0') cnt++;
		else {
			if (cnt == 0) ch[i] = '0'; else cnt--;
		}
	}
	for (int i = 0; i < n; i++) printf("%c",ch[i]);
	printf("\n");
} 

