#include <iostream>
#include <cmath>
using namespace std;

// Round x to nearest 10^b according to problem rules
int roundToPower(int x, int b) {
    int power = (int)pow(10, b);
    int digit = (x / (int)pow(10, b-1)) % 10;  // b-th digit from right

    if (digit >= 5) {
        x += power;
    }
    x -= x % power;  // zero out digits including and to right of b-th digit
    return x;
}

// Chain round x to nearest 10^P
int chainRound(int x) {
    // Find P such that 10^P >= x
    int P = 1;
    while (pow(10, P) < x) P++;

    for (int b = 1; b <= P; b++) {
        x = roundToPower(x, b);
    }
    return x;
}

int main() {
    int x;
    cout << "Enter a positive integer: ";
    cin >> x;

    // Find P for direct rounding
    int P = 1;
    while (pow(10, P) < x) P++;

    int direct = roundToPower(x, P);
    int chain = chainRound(x);

    cout << "Direct rounding: " << direct << "\n";
    cout << "Chain rounding: " << chain << "\n";

    if (direct == chain) {
        cout << "Both roundings are the same.\n";
    } else {
        cout << "Roundings differ.\n";
    }

    return 0;
}
