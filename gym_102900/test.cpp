/*  @author: AiharaShiro
    @createdate: 2020-12-18 13:38:58
    @Email£º1150811645@qq.com  */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int root = 0;
int nowcnt = 1;
int sum;
string s;
vector<string> roads;

struct node{
    int type;
    int cntok;
    bool nt;
    map<string,int> child;
};

node tree[1000005];

void init(){
    for (int i = 0; i <= nowcnt;i++){
        tree[i].type = -1;
        tree[i].child.clear();
        tree[i].cntok = 0;
        tree[i].nt = false;
    }
    sum = 0;
    nowcnt = 1;
    root = 0;
    tree[root].type = 0;
}

void getroad(string s){
    roads.clear();
    string tmp = "";
    for (int i = 0; i < s.length();i++){
        if (s[i] == '/'){
            roads.push_back(tmp);
            tmp = "";
        }
        else {
            tmp.push_back(s[i]);
        }
    }
    roads.push_back(tmp);
    return;
}

void makefile(int ty){
    int rt = root;
    for (int i = 0; i < roads.size() - 1;i++){
        if (tree[rt].child.count(roads[i]) == 0){
            tree[nowcnt].type = 0;
            tree[rt].child[roads[i]] = nowcnt++;
        }
        rt = tree[rt].child[roads[i]];
    }
    if (ty == 1)
        tree[rt].cntok++;
    else
        tree[rt].nt = true;
    return;
}

int getans(int pos){
    bool flag = true;
    int ans = 0;
    for (auto i = tree[pos].child.begin(); i != tree[pos].child.end();i++){
        int tp = getans(i->second);
        if (tp == -1)
            ans++;
        else{
            ans += tp;
            flag = false;
        }
    }
    ans += tree[pos].cntok;
    if (tree[pos].nt == true){
        flag = false;
    }
    if (flag)
        return -1;
    else
        return ans;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n;i++){
            cin >> s;
            getroad(s);
            makefile(1);
        }
        for (int i = 0; i < m;i++){
            cin >> s;
            getroad(s);
            makefile(2);
        }
        int tp = getans(root);
        int ans = 0;
        if (tp == -1) 
            ans = tree[root].cntok + tree[root].child.size();
        else
            ans = tp;
        cout << ans << endl;
    }
    return 0;
} 

