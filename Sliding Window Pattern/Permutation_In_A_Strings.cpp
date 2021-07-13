#include <iostream>
#include <map>
#include <string>
using namespace std;

bool permutationInAString(string s, string p) {
    int windowStart = 0, matched = 0;
    map<char, int> dict;
    for(int i = 0; i < p.length(); i++) {
        char str = p[i];
        dict[str] = 1;
    }
    
    for(int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
        char currChar = s[windowEnd];
        if (dict.find(currChar) != dict.end()) {
            dict[currChar]--;
            if (dict[currChar] == 0)
                matched++;
        }
        if (matched == dict.size()) {
            return true;
        }
        if (windowEnd >= (p.length() - 1)) {
            char leftChar = s[windowStart];
            if (dict.find(leftChar) != dict.end()) {
                if (dict[leftChar] == 0)
                    matched--;
                dict[leftChar]++;
            }
        }
    }
    return false;
}

int main() {
    string s = "eidboaoo";
    string p = "ab";
    cout<<permutationInAString(s, p)<<endl;
    return 0;
}