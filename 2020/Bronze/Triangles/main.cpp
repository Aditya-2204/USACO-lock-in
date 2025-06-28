#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int maxAreaTwice = 0;

    for (auto &p : points) {
        int x0 = p.first;
        int y0 = p.second;

        // Collect candidates
        vector<int> sameX;
        vector<int> sameY;

        for (auto &q : points) {
            if (q == p) continue;
            if (q.first == x0) {
                sameX.push_back(q.second);
            }
            if (q.second == y0) {
                sameY.push_back(q.first);
            }
        }

        // Try all pairs
        for (int y1 : sameX) {
            for (int x1 : sameY) {
                int base = abs(x1 - x0);
                int height = abs(y1 - y0);
                int areaTwice = base * height;
                if (areaTwice > maxAreaTwice) {
                    maxAreaTwice = areaTwice;
                }
            }
        }
    }

    cout << maxAreaTwice << endl;
}
