#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int trie[300005][30]; //字典树
int fail[300005];     //跳转数组
multiset<int> flag[300005];     //是否为终止节点
int tot;
int pos[300005];
int val[300005];

void trieinsert(char str[],int id)
{
    int len = strlen(str);
    int rt = 0;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (!trie[rt][id])
        {
            trie[rt][id] = ++tot;
        }
        rt = trie[rt][id];
    }
    flag[rt].insert(0);
    pos[id] = rt;
    val[id] = 0;
}

void change(int id,int valt){
    flag[pos[id]].erase(flag[pos[id]].find(val[id]));
    flag[pos[id]].insert(valt);
    val[id] = valt;
    return;
}

void getfail()
{ //BFS求fail数组
    queue<int> que;
    fail[0] = 0;
    for (int i = 0; i < 26; i++)
    { //与根节点直接相连的fail函数为0，并将其入队。
        if (trie[0][i])
        {
            fail[trie[0][i]] = 0;
            que.push(trie[0][i]);
        }
    }

    while (!que.empty())
    {
        int rt = que.front();
        que.pop();
        for (int i = 0; i < 26; i++)
        {
            if (!trie[rt][i])
            { //失配
                trie[rt][i] = trie[fail[rt]][i];
            }
            else
            {
                fail[trie[rt][i]] = trie[fail[rt]][i];
                que.push(trie[rt][i]);
            }
        }
    }
}

pair<int,int> find(int rt){
    if (rt == 0)
        return make_pair(rt, -1);
    if (flag[rt].size())
        return make_pair(rt, *flag[rt].rbegin());
    auto tp = find(fail[rt]);
    if (fail[rt] != tp.first)
        fail[rt] = tp.first;
    return tp;
}

int query(char str[])
{
    int len = strlen(str);
    int rt = 0;
    int ans = -1;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        rt = trie[rt][id];
        int temp = rt;
        while (temp != 0)
        {
            auto tp = find(temp);
            ans = max(ans, tp.second);
            temp = fail[tp.first];
        }
    }
    return ans;
}

char inputs[300005];

int main(){
    memset(val, -1, sizeof(val));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        scanf("%s", inputs);
        trieinsert(inputs, i);
    }
    getfail();
    for (int i = 1; i <= m;i++){
        int q;
        scanf("%d", &q);
        if (q == 1){
            int idp, v;
            scanf("%d%d", &idp, &v);
            change(idp, v);
        }
        else{
            scanf("%s", inputs);
            int ans = query(inputs);
            printf("%d\n", ans);
        }
    }
    return 0;
}
