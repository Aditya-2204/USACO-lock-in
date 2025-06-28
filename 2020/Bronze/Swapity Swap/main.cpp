#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    pair<int, int> sw[2];
    for (int i = 0; i < 2; i++) {
        cin >> sw[i].first >> sw[i].second;
    }

    for (int i = 0; i < K; i++) {
        reverse(arr.begin() + sw[0].first - 1, arr.begin() + sw[0].second);
        reverse(arr.begin() + sw[1].first - 1, arr.begin() + sw[1].second);
    }

    for (auto x : arr) {
        cout << x << "\n";
    }
}
