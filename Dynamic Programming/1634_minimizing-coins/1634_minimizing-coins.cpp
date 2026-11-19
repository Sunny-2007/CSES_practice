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
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    v[0] = 0;
    const int MAX = 1e9;
    for(int i = 1; i <= x; ++i) {
        v[i] = MAX;
    }
    for (int& coin : c) {
        for (int j = coin; j <= x; ++j) {
            v[j] = min(v[j-coin]+1, v[j]);
        }
    }
    if(v[x] >= MAX) cout << -1 << '\n';
    else cout << v[x] << '\n';
    return 0;
}