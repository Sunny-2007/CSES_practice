#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fio ios::sync_with_stdio(false); cin.tie(nullptr)

const int mxn = 2e5+5;
signed main(void) {
    fio;
    int n, x; cin >> n >> x;
    vector<int> v(n);
    map<int, int> m; //key = 前綴和, value = index 
    int res = 0;
    int cnt = 0;
    m[0] = 1;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        res = (res + v[i] + (int) 1e9) % n;
        cnt += m[res];
        m[res] += 1;
    }
    cout << cnt << '\n';
    return 0;
}
