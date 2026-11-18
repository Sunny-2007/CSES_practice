#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 2e5 + 5;
int n;
int task;
vector<int> k(mxn);
int cnt(int m) {
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += m / k[i];
        if(sum >= task) {
            return task;
        } 
    }
    return sum;
}
int bin(int l, int r) {
    int mid;
    while(l < r) {
        mid = (l+r)/2;
        int now = cnt(mid);
        if(now < task) l = mid + 1;
        else r = mid;
    }
    return r;
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> task;
    for(int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    cout << bin(1, 1e18);
    return 0;
}
