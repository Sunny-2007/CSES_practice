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
    sort(a.begin()+1, a.begin()+n+1);
    for(int i = 1; i <= n - 3; ++i) {
        for(int j = i + 1; j <= n - 2; ++j) {
            int l = j + 1;
            int r = n;
            int part = a[i].first + a[j].first;
            while(l < r) {
                int s = part + a[l].first + a[r].first;
                if(s > x) {
                    r--;
                }
                else if(s < x) {
                    l++;
                }
                else {
                    cout << a[i].second << " " << a[j].second << " "
                    << a[l].second << " " << a[r].second << '\n';
                    return 0;
                }           
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
