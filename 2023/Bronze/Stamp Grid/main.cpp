#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<string> grid(N);
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
        }

        int K;
        cin >> K;
        vector<string> stamp(K);
        for (int i = 0; i < K; ++i) {
            cin >> stamp[i];
        }

        vector<vector<char>> ans(N, vector<char>(N, '.'));
        for (int rot = 0; rot < 4; ++rot) {
            for (int i = 0; i <= N - K; ++i)
                for (int j = 0; j <= N - K; ++j) {
                    bool match = true;
                    for (int a = 0; a < K && match; ++a)
                        for (int b = 0; b < K; ++b)
                            if (!(grid[i + a][j + b] == '*' || stamp[a][b] == '.')) {
                                match = false;
                                break;
                            }
                    if (match)
                        for (int a = 0; a < K; ++a)
                            for (int b = 0; b < K; ++b)
                                if (stamp[a][b] == '*') ans[i + a][j + b] = '*';
                }
            vector<string> new_stamp(K, string(K, '.'));
            for (int i = 0; i < K; ++i)
                for (int j = 0; j < K; ++j) {
                    new_stamp[j][K - 1 - i] = stamp[i][j];
                }
            stamp = new_stamp;
        }
        bool isEqual = true;
        for (int i = 0; i < N; ++i)
            if (grid[i] != string(ans[i].begin(), ans[i].end())) {
                isEqual = false;
                break;
            }
        cout << (isEqual ? "YES" : "NO") << '\n';
    }

    return 0;
}