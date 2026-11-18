#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 2e5 + 5;



vector<pair<int, int>> v;

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    pair<int, int> p;
    for(int i = 1; i <= n; ++i) {
        cin >> p.first >> p.second; //first = time, second = deadline
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    int time = 0;
    int sum = 0;
    for(auto task : v) {
        time += task.first;
        sum += (task.second - time);
    }
    cout << sum << '\n';
    return 0;
}
