#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> cowHeight(N);
    vector<long long> candyHeight(M);

    for (int i = 0; i < N; ++i) {
        cin >> cowHeight[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> candyHeight[i];
    }

    vector<long long> eaten(N, 0);

    for (int i = 0; i < M; ++i) {
        long long cane = candyHeight[i];
        long long current_base = 0;

        fill(eaten.begin(), eaten.end(), 0); // Reset eaten this round

        for (int j = 0; j < N; ++j) {
            if (current_base >= cane) {
                break; // No more candy left to eat
            }

            if (current_base >= cowHeight[j]) {
                eaten[j] = 0;
            } else {
                eaten[j] = min(cowHeight[j], cane) - current_base;
                current_base += eaten[j];
            }
        }

        // Update cow heights
        for (int j = 0; j < N; ++j) {
            cowHeight[j] += eaten[j];
        }
    }

    for (auto h : cowHeight) {
        cout << h << '\n';
    }
}
