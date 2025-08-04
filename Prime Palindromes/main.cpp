/*
ID: aditya_10
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Generate palindromes by mirroring digits
void generatePalindromes(int a, int b, vector<int>& result) {
    // 1-digit palindromes
    for (int i = 1; i < 10; ++i) {
        if (i >= a && i <= b && isPrime(i))
            result.push_back(i);
    }

    // 2 to 8 digit palindromes
    for (int len = 2; len <= 8; ++len) {
        int half = (len + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);

        for (int i = start; i < end; ++i) {
            string s = to_string(i);
            string rev = s;
            if (len % 2 == 1)
                rev.pop_back();
            reverse(rev.begin(), rev.end());
            string palStr = s + rev;
            int pal = stoi(palStr);
            if (pal > b) return;
            if (pal >= a && isPrime(pal))
                result.push_back(pal);
        }
    }
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    vector<int> result;
    generatePalindromes(a, b, result);

    for (int p : result)
        cout << p << '\n';
}
