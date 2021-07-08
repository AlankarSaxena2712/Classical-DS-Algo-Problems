#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int findSubString(string s) {
    int windowStart = 0, maxLength = 0;
    unordered_map<char, int> dict;
    for(int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
        char currChar = s[windowEnd];
        if (dict.count(currChar) > 0)
            windowStart = max(windowStart, dict[currChar] + 1);
        dict[currChar] = windowEnd;
        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
}


int main() {
    string s = "abcabcbb";
    cout<<findSubString(s)<<endl;
    return 0;
}