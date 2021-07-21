#include <iostream>
#include <vector>
using namespace std;

bool subSetSum(int n, vector<int> arr, int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (arr[n - 1] > sum)
        return subSetSum(n - 1, arr, sum);
    return subSetSum(n - 1, arr, sum - arr[n - 1]) || subSetSum(n - 1, arr, sum);
}

int main() {
    int n = 5, sum = 11;
    vector<int> arr = {6, 19, 4, 10, 1};
    bool result = subSetSum(n, arr, sum);
    cout<<"Result : "<<result<<endl;
    return 0;
}