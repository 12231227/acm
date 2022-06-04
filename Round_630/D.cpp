#include <bits/stdc++.h>
using namespace std;

int a[5][5];

int main(){
	int k;
	scanf("%d",&k);
	int s = (1 << 18) - 1;
	int nk = s ^ k;
	cout << 4 << " " << 4 << endl;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4;j++)
			if (i == 1 || j == 1 || i == 4 || j == 4) a[i][j] = nk; else a[i][j] = k;
	a[4][4] = k; a[1][1] = a[1][2] = a[4][3] = s;
	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 4; j++)
			printf("%d " , a[i][j]);
		printf("\n");
	}
} 
