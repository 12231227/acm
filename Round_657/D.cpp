#include <bits/stdc++.h>
using namespace std;

struct node{
    int v;
    int pos;
    bool operator < (const node a) const{
        return v < a.v;
    }
};
node inputs[100005];

int main(){
    std::ios::sync_with_stdio(false);
    int n,h,m,k;
    cin >> n >> h >> m >> k;
    int hh,mm;
    for (int i = 1;i <= n;i++){
        cin >> hh >> mm;
        inputs[i].v = mm % (m / 2);
        inputs[i].pos = i;
    }
    int f = -1;
    sort(inputs,inputs + n);
    int ans = n + 1;
    for (int i = 0;i < n;i++){
        node qian;
        qian.v = (inputs[i].v - k + (m / 2)) % (m / 2);
        int p = upper_bound(inputs,inputs + n,qian) - inputs;
        int tmpans = 0;
        if (qian.v < inputs[i].v){
            if (ans < i - p){
                ans = i - p;
                f = qian.v;
            }
            //ans = min(ans,i - p);
        }
        else {
            if (ans < i + n - p){
                ans = i + n - p;
                f = qian.v;
            }
            //ans = min(ans, i + n - p);
        }
        node hou;
        hou.v = (inputs[i].v + k) % (m / 2);
        p = lower_bound(inputs,inputs + n,hou) - inputs;
        if (hou.v > inputs[i].v){
            if (ans < p - i){
                ans = p - i;
                f = inputs[i].v;
            }
            //ans = min(ans,p - i);
        }
        else {
            if (ans < n - i + p){
                ans = n - i + p;
                f = inputs[i].v;
            }
            //ans = min(ans,n - i + p);
        }
    }
    cout <<  ans << " " << f << endl;
    int pos = 1;
    int pos = upper_bound(inputs,inputs+n,f) - inputs;
    for (int i = 0;i < ans;i++){
        cout << inputs[pos++].pos << " ";
    }
    cout << endl;
    return 0;
}
