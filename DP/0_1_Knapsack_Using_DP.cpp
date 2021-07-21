#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n, vector<vector<int>> DP) {
    if (n == 0 || W == 0) 
        return 0;
    if (DP[n][W] != -1)
        return DP[n][W];
    if (wt[n - 1] > W) {
        DP[n][W] = knapsack(W, wt, val, n - 1, DP);
        return DP[n][W];
    }
    DP[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, DP), knapsack(W, wt, val, n - 1, DP));
    return DP[n][W];
}

int main() {
    int n = 4;
    vector<int> wt = {1, 3, 1, 2};
    vector<int> val = {10, 5, 30, 20};
    int W = 2;
    vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));
    int profit = knapsack(W, wt, val, n, dp);
    cout<<"Max Profit : "<<profit<<endl;
    return 0;
}