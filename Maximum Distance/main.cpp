#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    for (int i = 0; i < N; i++) cin >> y[i];

    long long maxDist = 0; // use long long to avoid overflow
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            long long distSq = dx * dx + dy * dy;
            maxDist = max(maxDist,distSq);
        }
    }

    cout << maxDist << "\n";
    return 0;
}