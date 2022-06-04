#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,x,y,x1,y1,x2,y2;

bool in() { return x + b - a <= x2 && x + b - a >= x1 && y + d - c <= y2 && y + d - c >= y1; }
bool check() { return (x1 == x2 && (a != 0 || b != 0)) || (y1 == y2 && (c != 0 || d != 0)); }
int main() {
	int _;
    for (scanf("%d",&_);_;_--) {
        scanf("%d %d %d %d", &a,&b,&c,&d);
        scanf("%d %d %d %d %d %d", &x,&y,&x1,&y1,&x2,&y2);
        int wid = b - a;
        int hei = d - c;
        if (in()) {
        	if (check()) printf("NO\n"); else printf("YES\n");
        }
        else printf("NO\n");
    }
}
