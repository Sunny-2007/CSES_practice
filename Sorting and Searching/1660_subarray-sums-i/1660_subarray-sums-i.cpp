#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int mxn = 2e5+5;
vector<int> v(mxn);
//sliding window
signed main(void) {
    fio;
    int n; cin >> n;
    int x; cin >> x;
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    int l = 1; int r = 1;
    int s = v[1];
    int cnt = 0;
    while(l <= n && r <= n) {
        if(s < x) {
            r++;
            s += v[r];
        }
        else {
            if(s == x) cnt++;
            s -= v[l];
            l++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
