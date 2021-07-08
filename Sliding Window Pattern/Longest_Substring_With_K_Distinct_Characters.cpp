#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int findLength(string s, int k) {
    int n = s.size();
    if (n == 0)
        return -1;
    if (n < k)
        return n;

    int windowStart = 0, maxLength = 0;
    map<char, int> dict;

    for (int windowEnd = 0; windowEnd < n; windowEnd++) {
        char str = s[windowEnd];
        if (dict.count(str) < 1)
            dict.insert(pair<char, int>(str, 1));
        else 
            dict[str] = dict[str] + 1;
        while(dict.size() > k) {
            dict[s[windowStart]] = dict[s[windowStart]] - 1;
            if (dict[s[windowStart]] == 0)
                dict.erase(s[windowStart]);
            windowStart++;
        }
        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
}

int main() {
    string s = "leetcode";
    int k = 2;
    cout<<findLength(s, k)<<endl;
    return 0;
}