/*
ID: aditya_10
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int M, S, C;
    cin >> M >> S >> C;

    vector<int> occupied_stalls(C);
    for (int i = 0; i < C; i++) {
        cin >> occupied_stalls[i];
    }

    sort(occupied_stalls.begin(), occupied_stalls.end());

    // Compute consecutive differences
    vector<int> gaps;
    for (int i = 1; i < C; i++) {
        gaps.push_back(occupied_stalls[i] - occupied_stalls[i - 1] - 1);
    }

    // Sort gaps descending
    sort(gaps.rbegin(), gaps.rend());

    int total_length = occupied_stalls.back() - occupied_stalls.front() + 1;

    int gaps_to_remove = min(M-1, (int)gaps.size());

    for(int i=0;i<gaps_to_remove;i++) {
        total_length -= gaps[i];
    }
    
    cout << total_length << endl;
}