#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fio ios::sync_with_stdio(false); cin.tie(nullptr)
const int mxnr = 2505;
struct Edge {int u, v, w;};
vector<Edge> edges(5005); //pii (v, w)
signed main(void) {
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    return 0;
}