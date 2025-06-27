/*
ID: aditya_10
LANG: C++
TASK: test
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);

    int N, K;
    cin >> N >> K;

    vector<int> diamonds(N);
    for (int i = 0; i < N; ++i) {
        cin >> diamonds[i];
    }

    sort(diamonds.begin(), diamonds.end());

    int maxCount = 0;
    int left = 0;

    for (int right = 0; right < N; ++right) {
        while (diamonds[right] - diamonds[left] > K) {
            left++;
        }
        maxCount = max(maxCount, right - left + 1);
    }

    cout << maxCount << endl;

    return 0;
}
