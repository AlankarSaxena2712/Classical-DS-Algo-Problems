#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) 
        return 0;
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n-1);
    return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
}

int main() {
    int n = 4;
    int wt[] = {1, 3, 1, 2};
    int val[] = {10, 5, 30, 20};
    int W = 2;
    int profit = knapsack(W, wt, val, n);
    cout<<"Max Profit : "<<profit<<endl;
    return 0;
}