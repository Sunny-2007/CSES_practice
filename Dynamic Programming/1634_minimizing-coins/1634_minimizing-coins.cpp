#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fio ios::sync_with_stdio(false); cin.tie(nullptr)

const int mxn = 1e6+5, mod = 1e9+7;
vector<int> v(mxn);
int c[101];
//each cell records coins needed
signed main(void) {
    fio;
    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    v[0] = 0;
    bool modi = 0;
    for(int i = 1; i <= x; ++i) {
        v[i] = LLONG_MAX;
    }
    // for(int i = 1; i <= x; ++i) {
    //     modi = 0;
    //     for(int j = 1; j <= n; ++j) {
    //         if(i - c[j] < 0 || v[i-c[j]] == LLONG_MAX || v[i-c[j]] == -1) continue;
    //         modi = 1;
    //         v[i] = min(v[i-c[j]] + 1, v[i]);
    //     }
    //     if(!modi) v[i] = -1;
    // }
    
    cout << v[x] << '\n';
    return 0;
}