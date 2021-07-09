#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestRepeatingCharacterReplacement(string s, int k) {
    int windowStart = 0, maxLength = 0, maxRepeatLetter = 0;
    unordered_map<char, int> dict;
    for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
        char currChar = s[windowEnd];
        dict[currChar]++;
        maxRepeatLetter = max(maxRepeatLetter, dict[currChar]);
        if ((windowEnd - windowStart + 1 - maxRepeatLetter) > k) {
            char leftChar = s[windowStart];
            dict[leftChar]--;
            windowStart++;
        }
        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
}

int main() {
    string s = "aabccbb";
    int k = 2;
    cout<<longestRepeatingCharacterReplacement(s, k)<<endl;
    return 0;
}