#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
 
int cnt[100005];
int ans = 0;
vector<int> nowinput;
 
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int k;
        cin >> k;
        nowinput.clear();
        for (int j = 1; j <= k;j++){
            int tmp;
            cin >> tmp;
            nowinput.push_back(tmp);
            if (ans <= cnt[tmp]){
                ans++;
            }
        }
        for (int j = 0; j < k;j++){
            cnt[nowinput[j]] = ans;
        }
    }
    cout << ans << endl;
    return 0;
}