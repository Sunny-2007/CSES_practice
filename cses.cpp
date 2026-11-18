#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fio ios::sync_with_stdio(false); cin.tie(nullptr)

const int mxn = 1e6+5, mod = 1e9+7;
map<int, int> m;
vector<int> v(mxn);
signed main(void) {
    fio;
    int n; cin >> n;
    v[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 6; ++j) {
            if(i - j < 0) break;
            v[i] = (v[i] + v[i-j]) % mod;
        }
    }
    cout << v[n] << '\n';
    return 0;
}