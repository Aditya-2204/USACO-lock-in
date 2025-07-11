/*
ID: aditya_10
LANG: C++
TASK: dualpal
*/

#include <iostream>
using namespace std;

string toBaseString(int decimal, int base) {
    string result;
    while(decimal > 0) {
        int digit = decimal % base;
        result = char('0' + digit) + result;
        decimal /= base;
    }
    return result;
}

bool isPalindrome(const string& s) {
    int n = s.size();
    for(int i = 0; i < n/2; i++) {
        if(s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int N, S;
    cin >> N >> S;

    int found = 0;
    int n = S + 1;

    while (found < N) {
        int count = 0;
        for (int b = 2; b <= 10; b++) {
            if (isPalindrome(toBaseString(n, b))) {
                count++;
            }
        }
        if (count >= 2) {
            cout << n << endl;
            found++;
        }
        n++;
    }
}
