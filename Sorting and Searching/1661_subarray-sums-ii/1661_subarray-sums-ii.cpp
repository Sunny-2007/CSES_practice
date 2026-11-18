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
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        m[sum+1e9] += 1;
        cnt += m[sum - x+1e9];
        if(m[1e9] == 0 && sum == x) cnt++; 
    }
    cout << cnt << '\n';
    return 0;
}
