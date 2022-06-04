#include <cstdio>
using namespace std;
int main(){
//	int sg[1000];
	//3 1110 1110 ...
	//6 110 1110 ..
	//9 110 110 1110...
	//12 110 110 110 1110
//	int k = 12;
//	sg[0] = 0;//±Ø°Ü
//	sg[1] = sg[2] = sg[k] = 1;
//	for (int i = 3; i <= 100; i++)
//	 if (i >= k) sg[i] = ((sg[i - 1] & sg[i - 2] & sg[i - k]) == 0);
//	 else sg[i] = (sg[i - 1] & sg[i - 2]) == 0;
//	for (int i = 0; i <= 100; i++) {
//		printf("%d ",sg[i]);
//		if (i % 10 == 0) printf("\n");
//	}
	int t;
	scanf("%d",&t);
	while (t--){
		int n,k;
		scanf("%d %d",&n,&k);
		if (n == 0) printf("Bob\n");
		else {
			if (k % 3 != 0) {
				if (n % 3 == 0) printf("Bob\n");
				else printf("Alice\n");
			}
			else{
				int num = n % (k + 1);
				if ((num != k && num % 3 == 0) || (num == 0)) printf("Bob\n");
				else printf("Alice\n");
			}
		}
	}
} 
