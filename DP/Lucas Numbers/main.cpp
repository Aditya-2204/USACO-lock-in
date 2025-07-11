#include <iostream>
#include <vector>
using namespace std;

int soln(int n, vector<int>& memo) {
    if (n == 0) {
        return 2;
    }
    if (n == 1) {
        return 1;
    }

    // If we've already computed soln(n), return it
    if (memo[n] != -1) {
        return memo[n];
    }

    // Otherwise, compute and store it
    memo[n] = soln(n - 1, memo) + soln(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 1;
    // Initialize a vector of size n+1, filled with -1
    vector<int> memo(n + 1, -1);

    cout << soln(n, memo);

    return 0;
}
