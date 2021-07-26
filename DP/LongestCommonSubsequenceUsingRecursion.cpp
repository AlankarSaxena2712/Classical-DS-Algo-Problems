#include <iostream>
#include <string>
using namespace std;

int lcs(string a, string b, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (a[m - 1] == b[n - 1])
        return 1 + lcs(a, b, m - 1, n - 1);
    return max(lcs(a, b, m - 1,n), lcs(a, b, m, n - 1));
}

int main() {
    string a = "gxtxayb", b = "aggtab";
    int m = a.length(), n = b.length();
    int result = lcs(a, b, m, n);
    cout<<result;
    return 0;	
}