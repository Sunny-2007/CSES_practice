#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mxn = 5005;
vector<pair<int, int>> a(mxn);

//two pointer
signed main(void) {
    int n; cin >> n;
    int x; cin >> x;
    int num;
    for(int i = 1; i <= n; ++i) {
        cin >> num;
        a[i] = {num, i};
    }
    bool found = false;
    sort(a.begin()+1, a.begin()+n+1);
    for(int i = 1; i <= n; ++i) {
        int l = i + 1;
        int r = n;
        while(l < r) {
            if(a[i].first + a[l].first + a[r].first > x) {
                r--;
            }
            else if(a[i].first + a[l].first + a[r].first < x) {
                l++;
            }
            else {
                found = true;
                cout << a[i].second << " " << a[l].second << " " << a[r].second << '\n';
                break;
            }           
        }
        if(found) break;
    }
    if(!found) cout << "IMPOSSIBLE\n";
    return 0;
}
