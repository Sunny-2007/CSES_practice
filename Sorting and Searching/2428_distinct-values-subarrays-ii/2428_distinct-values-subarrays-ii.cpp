#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fio ios::sync_with_stdio(false); cin.tie(nullptr)

const int mxn = 2e5+5;
map<int, int> m;
vector<int> v(mxn);
signed main(void) {
    fio;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    int dis = 0;
    int l = 1;
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if (m[v[i]] == 0) {
            dis++;
        }
        m[v[i]]++;
        while (dis > k) {
            m[v[l]]--;
            if(m[v[l]] == 0) dis--;
            l++;
        }
        cnt += (i - l + 1);
    }
    cout << cnt << '\n';
    return 0;
}
