#include <bits/stdc++.h>

using namespace std;

long lps(string a, string b, int m, int n, vector<vector<int>> dp) {
    for(int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[m][n];
}

int main() {
    string s = "bbbab";
    int m = s.length(), n;
    n = m;
    string rev;
    for(int i = m - 1; i >= 0; i--)
        rev.push_back(s[i]);
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
    long result = lps(s, rev, m, n, dp);
    cout<<result;
    return 0;
}