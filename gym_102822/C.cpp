#include <bits/stdc++.h>
using namespace std;

int trie[600010][30]; //可储存100005个节点，字符集总数30
int cnt[600010];
int val[600010];
int fa[600010];
map <int,int> mp;

int tot; //节点数
bool flag;

struct node {
    int x;
    bool operator < (const node &rh) const {
        return mp[x] < mp[rh.x];
    }
};

void trieinsert(string str, int v)
{
    int len = str.length();
    int rt = 0; //从0（root节点）开始插入
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (!trie[rt][id])
        { //判断子节点是否存在
            cnt[rt]++;
            trie[rt][id] = ++tot;
            fa[tot] = rt;
        }
        rt = trie[rt][id];
    }
    if (val[rt] != 0 && val[rt] != v)
        flag = false;
    val[rt] = v; //标记为终止节点
}

void init()
{
    mp.clear();
    for (int i = 0; i <= tot; i++)
    {
        val[i] = 0;
        cnt[i] = 0;
        fa[i] = -1;
        for (int j = 0; j < 26; j++)
        {
            trie[i][j] = 0;
        }
    }
    tot = 0;
    return;
}

int solve()
{
    int ans = tot + 1;
    priority_queue<node> que;
    for (int i = 0; i <= tot; i++)
    {
        if (cnt[i] == 0)
        {
            if (val[i]) ++mp[val[i]];
        } 
    }
    for (int i = 0; i <= tot; i++)
    {
        if (cnt[i] == 0)
        {
            que.push(node{i});
        } 
    }
    
    while (!que.empty())
    {
        int now = que.top().x;
        que.pop();
        if (now == 0)
            continue;
        if (val[fa[now]] == 0 || val[fa[now]] == val[now])
        {
            cnt[now]--;
            cnt[fa[now]]--;
            if (val[now] && val[fa[now]] == val[now]) --mp[val[now]];
            val[fa[now]] = val[now];
            ans--;
            if (cnt[fa[now]] == 0)
                que.push(node{fa[now]});
        }
    }
    set<int> st;
    for (int i = 0; i <= tot; i++)
    {
        if (val[i] == 0)
            continue;
        if (cnt[i] >= 0)
        {
            if (st.count(val[i]))
                return -1;
            st.insert(val[i]);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    int ctt = 0;
    while (T--)
    {
        ctt++;
        flag = true;
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string tp;
            int v;
            cin >> tp >> v;
            trieinsert(tp, v);
        }
        cout << "Case #"<< ctt <<": ";
        if (flag)
            cout << solve() << endl;
        else
            cout << -1 << endl;
    }
}