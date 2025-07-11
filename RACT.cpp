#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double triangle_area(double b, double h) {
    return (b * h) / 2.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, d, h;
        cin >> n >> d >> h;

        vector<int> y(n);
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
        }

        double total = 0.0;

        for (int i = 0; i < n; ++i) {
            total += triangle_area(d, h);

            if (i > 0) {
                int dh = y[i] - y[i - 1];
                int overlap_h = max(0, h - dh);
                if (overlap_h > 0) {
                    double overlap_b = d * (overlap_h / static_cast<double>(h));
                    total -= triangle_area(overlap_b, overlap_h);
                }
            }
        }

        cout << fixed << setprecision(10) << total << '\n';
    }

    return 0;
}
