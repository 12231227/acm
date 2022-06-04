/*  @author: AiharaShiro
    @createdate: 2021-01-25 14:44:16
    @Email：1150811645@qq.com  */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

map<int, int> xx;
map<int, int> yy;

int op[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

struct Line
{
    int x1, y1, x2, y2;
    int type;//1:横,2:竖
};


int keymap[550][550];
int EndFlag[550][550];
int vis[550][550][4];
vector<int> xp;
vector<int> yp;
vector<Line> lines;
int n;
int t;
int stx, sty;
int N, M;
int nowop;

int getdis(int x1, int y1, int x2, int y2) {
    if (x1 == x2)
        return abs(yp[y1 - 1] - yp[y2 - 1]);
    else
        return abs(xp[x1 - 1] - xp[x2 - 1]);
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        Line tmp;
        cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        if (tmp.x1 == tmp.x2)
            tmp.type = 1;
        else
            tmp.type = 2;
        xp.push_back(tmp.x1);
        xp.push_back(tmp.x2);
        yp.push_back(tmp.y1);
        yp.push_back(tmp.y2);
        lines.push_back(tmp);
    }
    sort(xp.begin(), xp.end());
    xp.erase(unique(xp.begin(), xp.end()), xp.end());
    sort(yp.begin(), yp.end());
    yp.erase(unique(yp.begin(), yp.end()), yp.end());
    N = xp.size();
    M = yp.size();
    for (int i = 0; i < N; i++) {
        xx[xp[i]] = i + 1;
    }
    for (int i = 0; i < M; i++) {
        yy[yp[i]] = i + 1;
    }
    if (lines[0].type == 1)
        nowop = 1;
    else
        nowop = 0;
    stx = xx[lines[0].x1];
    sty = yy[lines[0].y1];
    for (int i = 0; i < n; i++) {
        if (lines[i].type == 1) {
            int nowx = xx[lines[i].x1];
            int f = yy[lines[i].y1];
            int b = yy[lines[i].y2];
            if (f > b)
                swap(f, b);
            EndFlag[nowx][f] = 4;
            EndFlag[nowx][b] = 2;
            for (int i = f; i <= b; i++) {
                keymap[nowx][i]++;
            }
        }
        else {
            int nowy = yy[lines[i].y1];
            int f = xx[lines[i].x1];
            int b = xx[lines[i].x2];
            if (f > b)
                swap(f, b);
            EndFlag[f][nowy] = 3;
            EndFlag[b][nowy] = 1;
            for (int i = f; i <= b; i++) {
                keymap[i][nowy]++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 4; k++) {
                vis[i][j][k] = -1;
            }
        }
    }

    int nowt = 0;
    int ansx = -1;
    int ansy = -1;
    while (vis[stx][sty][nowop] == -1) {
        vis[stx][sty][nowop] = nowt;
        if (nowop == EndFlag[stx][sty] - 1) {
            nowop = (nowop + 2) % 4;
            continue;
        }
        else if (keymap[stx][sty] > 1) {
            nowop = (nowop + 1) % 4;
        }
        int nowdis = getdis(stx, sty, stx + op[nowop][0], sty + op[nowop][1]);
        if (nowt + nowdis < t) {
            nowt += nowdis;
            stx += op[nowop][0];
            sty += op[nowop][1];
        }
        else {
            ansx = xp[stx - 1] + op[nowop][0] * (t - nowt);
            ansy = yp[sty - 1] + op[nowop][1] * (t - nowt);
            break;
        }
    }

    if (ansx == -1) {
        int cyclen = nowt - vis[stx][sty][nowop];
        t %= cyclen;
        nowt = 0;
        while (nowt <= t) {
            if (nowop == EndFlag[stx][sty] - 1)
                nowop = (nowop + 2) % 4;
            else if (keymap[stx][sty] > 1) {
                nowop = (nowop + 1) % 4;

            }
            int nowdis = getdis(stx, sty, stx + op[nowop][0], sty + op[nowop][1]);
            if (nowt + nowdis < t) {
                nowt += nowdis;
                stx += op[nowop][0];
                sty += op[nowop][1];
            }
            else {
                ansx = xp[stx - 1] + op[nowop][0] * (t - nowt);
                ansy = yp[sty - 1] + op[nowop][1] * (t - nowt);
                break;
            }
        }
    }

    cout << ansx << " " << ansy << endl;

    return 0;
} 
