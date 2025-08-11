#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
bool col[8], diag1[15], diag2[15]; // diag1 = r+c, diag2 = r-c+7
char board[8][8];

void backtrack(int row) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '*') continue; // can't place queen here
        if (col[c] || diag1[row+c] || diag2[row-c+7]) continue; // attacked

        col[c] = diag1[row+c] = diag2[row-c+7] = true;
        backtrack(row + 1);
        col[c] = diag1[row+c] = diag2[row-c+7] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];

    backtrack(0);
    cout << ans << "\n";
}
