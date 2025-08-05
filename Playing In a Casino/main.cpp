#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> cards(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> cards[i][j];

        long long total = 0;

        for (int j = 0; j < m; ++j) {
            vector<int> col;
            for (int i = 0; i < n; ++i)
                col.push_back(cards[i][j]);

            sort(col.begin(), col.end());

            long long prefix_sum = 0;
            for (int i = 0; i < n; ++i) {
                total += 1LL * col[i] * i - prefix_sum;
                prefix_sum += col[i];
            }
        }

        cout << total << '\n';
    }

    return 0;
}
