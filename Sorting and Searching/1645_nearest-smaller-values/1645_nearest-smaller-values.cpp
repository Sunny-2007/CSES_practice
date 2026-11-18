#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;
const int mxn = 2e5+5;
stack<pii> st;
signed main(void) {
    int n; cin >> n;
    int num;
    for(int i = 1; i <= n; ++i) {
        cin >> num;
        int ans = 0;
        while(!st.empty()) {
            if(st.top().first >= num) st.pop();
            else {
                ans = st.top().second;
                break;
            }
        }
        st.push({num, i});
        cout << ans << " \n" [i == n];
    }
    return 0;
}
