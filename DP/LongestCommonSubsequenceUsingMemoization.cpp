#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n, vector<vector<int>> dp) {
    if (n == 0 || m == 0) 
        return 0;
    if (dp[m - 1][n - 1] != -1)
        return dp[m - 1][n - 1];
    if (a[m - 1] == b[n - 1]) {
        dp[m - 1][n - 1] = 1 + lcs(a, b, m - 1, n - 1, dp);
        return dp[m - 1][n - 1];
    }
    dp[m - 1][n - 1] = max(lcs(a, b, m - 1, n, dp), lcs(a, b, m, n - 1, dp));
    return dp[m - 1][n - 1];
}

int main() {
    string a = "aab", b = "aac";
    int m = a.length(), n = b.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
    int result = lcs(a, b, m, n, dp);
    cout<<result;
    return 0;
}