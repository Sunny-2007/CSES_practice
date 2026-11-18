#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
struct cus {
    int st;
    int ed;
    int ori;
};

bool cmp_cus (const cus& a, const cus& b) {
    if(a.st != b.st) return a.st < b.st;
    else {
        if(a.ed != b.ed) return a.ed < b.ed;
        else return a.ori < b.ori;
    }
}
vector<cus> v(mxn);
set<pair<int, int>> s;
vector<int> ans(mxn);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cus c; 
        c.ori = i;
        cin >> c.st >> c.ed;
        v[i] = c;
    }
    sort(v.begin() + 1, v.begin()+n+1, cmp_cus);
    for(int i = 1; i <= n; ++i) {
        auto it = s.lower_bound({v[i].st, LLONG_MIN});
        int id = 0;
        if(it == s.begin()) {
            id = s.size() + 1;
            
        }
        else {
            --it;
            id = it->second;
            s.erase(it);
        }
        ans[v[i].ori] = id;
        s.insert({v[i].ed, id});
    }
    cout << s.size() << '\n';
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n" [i == n];
    }
    return 0;
}
