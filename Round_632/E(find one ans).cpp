#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

int a[10];
bool vis[11][11];
int mat[4][4];

pair <int,int> ind;

int f1() {
	int x = ind.first;
	int y = ind.second;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			vis[i][j] = false;
	vis[x][y] = true;
	int cnt = 0;
	for (int i = 1; i <= 8; i++) {
		int mn = 10; int tx,ty;
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++) {
				if (vis[j][k]) continue;
				if (j == x || k == y) {
					if (mat[j][k] < mn) {
						mn = mat[j][k];
						tx = j; ty = k;
					}
				}
			}
		if (mn == 10) {
			cnt++;
			for (int j = 1; j <= 3; j++)
				for (int k = 1; k <= 3; k++) {
					if (vis[j][k]) continue;
					if (mat[j][k] < mn) {
						mn = mat[j][k];
						tx = j; ty = k;
					}
				}
		}
		vis[tx][ty] = true;
		x = tx; y = ty;
	}
	return cnt;
}

int f2() {
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			vis[i][j] = false;
	int x = ind.first;
	int y = ind.second;
	vis[x][y] = true;
	int cnt = 0;
	for (int i = 1; i <= 8; i++) {
		int mn = 10; int tx,ty;
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++) {
				if (vis[j][k]) continue;
				if (j == x || k == y || abs(j - x) == abs(k - y)) {
					if (mat[j][k] < mn) {
						mn = mat[j][k];
						tx = j; ty = k;
					}
				}
			}
		if (mn == 10) {
			cnt++;
			for (int j = 1; j <= 3; j++)
				for (int k = 1; k <= 3; k++) {
					if (vis[j][k]) continue;
					if (mat[j][k] < mn) {
						mn = mat[j][k];
						tx = j; ty = k;
					}
				}
		}
		vis[tx][ty] = true;
		x = tx; y = ty;
	}
	return cnt;
}

int main(){ 
	for (int i = 1; i <= 9; i++) a[i] = i;
//	mat[1][1] = 1; mat[1][2] = 2; mat[1][3] = 4;
//	mat[2][1] = 5; mat[2][2] = 3; mat[2][3] = 8;
//	mat[3][1] = 9; mat[3][2] = 6; mat[3][3] = 7;
//	int cnt1 = f1();
//	int cnt2 = f2();
//	printf("%d %d\n" , cnt1 , cnt2);
	
	do {
		for(int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++){
				mat[i][j] = a[(i - 1) * 3 + j];
				if (mat[i][j] == 1) ind = make_pair(i , j);
			}
		int cnt1 = f1();
		int cnt2 = f2();
		if (cnt1 < cnt2) {
			printf("%d %d\n" , cnt1, cnt2);
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) printf("%d " , mat[i][j]);
				puts("");
			}
			break;
		}
	}while (next_permutation(a + 1 , a + 10));
}
