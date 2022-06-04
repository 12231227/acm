#include <cstdio>
using namespace std;
const int maxn = 1e5;
char ch[maxn + 11];
int num[100];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",&ch);
	//o n e z r
	//one zero
	for (int i = 0; i < n; i++)
	 if (ch[i] == 'o') num[1]++;
	 else if (ch[i] == 'n') num[2]++;
	 else if (ch[i] == 'e') num[3]++;
	 else if (ch[i] == 'z') num[4]++;
	 else if (ch[i] == 'r') num[5]++;
	for (int i = 1; i <= num[2]; i++) printf("1 ");
	for (int i = 1; i <= num[5]; i++) printf("0 ");
	printf("\n");
} 

