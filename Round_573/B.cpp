#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

char st1[3],st2[3],st3[3];
int a[4];

bool equal(char x[],char y[]){
	return (x[0] == y[0]) && (x[1] == y[1]);
}

int doit(){
	int ans = 2;
	if (equal(st1,st2) && equal(st1,st3)) return 0;
	if (equal(st1,st2) || equal(st1,st3) || equal(st2,st3)) ans = 1;
	if (st1[1] == st2[1] && st1[1] == st3[1] && a[1] + 1 == a[2] && a[2] + 1 == a[3]) return 0;
	if (st1[1] == st2[1] && abs(st1[0] - st2[0]) == 1) ans = 1;
	if (st1[1] == st3[1] && abs(st1[0] - st3[0]) == 1) ans = 1;
	if (st3[1] == st2[1] && abs(st3[0] - st2[0]) == 1) ans = 1;
	if (st1[1] == st2[1] && abs(st1[0] - st2[0]) == 2) ans = 1;
	if (st1[1] == st3[1] && abs(st1[0] - st3[0]) == 2) ans = 1;
	if (st3[1] == st2[1] && abs(st3[0] - st2[0]) == 2) ans = 1;
	return ans;
}

int main(){
	scanf("%s %s %s",&st1,&st2,&st3);
	a[1] = st1[0] - '0';
	a[2] = st2[0] - '0';
	a[3] = st3[0] - '0';
	sort(a + 1, a + 4);
	printf("%d\n",doit());
}

