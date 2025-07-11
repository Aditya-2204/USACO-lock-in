/*
ID: aditya_10
TASK: palsquare
LANG: C++
*/

#include <iostream>
#include <string>
using namespace std;

string toBase(int n, int B) {
    string digits = "0123456789ABCDEFGHIJ";
    string result;
    while (n > 0) {
        result = digits[n % B] + result;
        n /= B;
    }
    return result.empty() ? "0" : result;
}

bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

int main() {
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);

    int B;
    cin >> B;

    for (int N = 1; N <= 300; N++) {
        int sq = N * N;
        string sqBase = toBase(sq, B);
        if (isPalindrome(sqBase)) {
            cout << toBase(N, B) << " " << sqBase << endl;
        }
    }

    return 0;
}
