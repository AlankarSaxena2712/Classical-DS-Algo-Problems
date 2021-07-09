#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int smallestSubContiguousSubArray(vector<int>& array, int n, int sum) {
    int winStart = 0, windowSum = 0, minLength = INT_MAX;
    for (int windowEnd = 0; windowEnd < n; windowEnd++) {
        windowSum = windowSum + array[windowEnd];
        while(windowSum >= sum) {
            minLength = min(minLength, windowEnd - winStart + 1);
            windowSum = windowSum - array[winStart];
            winStart++;
        }
    }   
    if (minLength == INT_MAX)
        return 0;
    return minLength;
}

int main() {
    vector<int> array;
    array.push_back(2);
    array.push_back(1);
    array.push_back(5);
    array.push_back(2);
    array.push_back(3);
    array.push_back(2);
    int n = 6;
    int result = smallestSubContiguousSubArray(array, n, 7);
    cout<<result<<endl;
    return 0;
}
