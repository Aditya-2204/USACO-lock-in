#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;

    vector<pair<int,int>> nums(N); // {value, original index}
    for (int i = 0; i < N; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1; // store 1-based index
    }

    // Sort by value
    sort(nums.begin(), nums.end());

    int l = 0, r = N - 1;
    while (l < r) {
        int sum = nums[l].first + nums[r].first;
        if (sum == x) {
            cout << nums[l].second << " " << nums[r].second << '\n';
            return 0;
        }
        if (sum < x) l++;
        else r--;
    }

    cout << "IMPOSSIBLE\n";
}
