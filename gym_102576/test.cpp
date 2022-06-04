#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue <int , vector <int> , less <int> > q;
    q.push(1); q.push(2);
    cout << q.top() << endl;
}