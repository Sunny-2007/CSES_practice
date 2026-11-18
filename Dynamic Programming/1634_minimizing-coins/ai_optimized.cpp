// CSES 1634 - Minimizing Coins
// AI 協助重構版本（對照：1634_minimizing-coins.cpp）
//
// dp[i] = 湊出金額 i 所需的最少硬幣數，湊不出來就是 INF
// dp[i] = min(dp[i - c] + 1)，對所有 c <= i 的硬幣取最小
// 時間 O(n * x)，空間 O(x)
//
// ── 學到的重點 ─────────────────────────────────────────────
// 1. 用「夠大的有限值」當 INF，不要用 LLONG_MAX
//    原版用 LLONG_MAX 表示「還沒算」、-1 表示「湊不出來」，所以每次轉移前
//    都要檢查兩種特殊值，避免 LLONG_MAX + 1 溢位。
//    改成 INF = 1e9 之後，INF + 1 不會溢位，而且 min() 會自動忽略它，
//    特殊值檢查和 modi flag 都可以拿掉。
//    → 「湊不出來」只在最後輸出時才轉成 -1。
//
// 2. vector<int> dp(x + 1, INF)
//    建構子可以直接填初始值，不必另外寫迴圈；大小用 x + 1，
//    而不是固定的 mxn 全域陣列。
//
// 3. range-based for：for (int c : coins)
//    不需要索引的時候，比 for (int j = 1; j <= n; ++j) ... c[j] 更簡潔，
//    也不會有 1-indexed / 0-indexed 搞混的問題。
//
// 4. 三元運算子輸出：cout << (dp[x] >= INF ? -1 : dp[x])
// ───────────────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;   // 用參照直接讀進 vector

    const int INF = 1e9;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; ++i)
        for (int c : coins)
            if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1);

    cout << (dp[x] >= INF ? -1 : dp[x]) << '\n';
}
