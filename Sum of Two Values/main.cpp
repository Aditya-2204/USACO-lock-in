#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

// Custom hash function to avoid collisions
struct SafeHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    unordered_map<int, int, SafeHash> seen;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        int complement = x - a[i];
        if (seen.count(complement)) {
            cout << seen[complement] << " " << i + 1 << "\n";
            return 0;
        }
        seen[a[i]] = i + 1;
    }

    cout << "IMPOSSIBLE\n";
}
