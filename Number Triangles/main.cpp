/*
ID: aditya_10
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <algorithm>
using namespace std;

int triangle[1005][1005];
int dp[1005][1005];

int main(){
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    int N;
    cin >> N;

    // Read input triangle (1-indexed)
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            cin >> triangle[i][j];

    // Base case
    dp[1][1] = triangle[1][1];

    // DP computation
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    // Find the max value in the last row
    int max_sum = 0;
    for (int j = 1; j <= N; j++) {
        max_sum = max(max_sum, dp[N][j]);
    }

    cout << max_sum << endl;

    return 0;
}
