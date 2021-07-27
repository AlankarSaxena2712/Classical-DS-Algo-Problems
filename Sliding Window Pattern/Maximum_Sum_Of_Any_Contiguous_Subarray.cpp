#include <iostream>
#include <vector>
using namespace std;
 
int contiguousSubarrayOfSizeKWithMaxSum(vector<int> array, int k) {
    int windowStart = 0, maxSum = 0, windowSum = 0;
    for (int windowEnd = 0; windowEnd < array.size(); windowEnd++) {
        windowSum = windowSum + array[windowEnd];
        if (windowEnd >= (k - 1) ) {
            maxSum = max(maxSum, windowSum);
            windowSum = windowSum - array[windowStart];
            windowStart = windowStart + 1;
        }
    }
    return maxSum;
}

int main() {
    vector<int> array = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int reuslt = contiguousSubarrayOfSizeKWithMaxSum(array, k);
    cout<<reuslt<<endl;
    return 0;
}