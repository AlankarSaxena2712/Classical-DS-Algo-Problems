#include <iostream>
#include <vector>
using namespace std;

bool subSetSum(int n, vector<int> arr, int sum, vector<vector<int>> dp) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];
    if (arr[n - 1] > sum)
        return dp[n - 1][sum] = subSetSum(n - 1, arr, sum, dp);
    return dp[n - 1][sum] = subSetSum(n - 1, arr, sum - arr[n - 1], dp) || subSetSum(n - 1, arr, sum, dp);
}

int main() {
    int n = 5, sum = 12;
    vector<int> arr = {6, 19, 4, 10, 1};
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
    bool result = subSetSum(n, arr, sum, dp);
    cout<<"Result : "<<result<<endl;
    return 0;
}