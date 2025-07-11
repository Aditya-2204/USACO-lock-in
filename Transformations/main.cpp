/*
ID: aditya_10
LANG: C++
TASK: transform
*/

#include <iostream>
#include <vector>

using namespace std;

struct Grid {
    vector<vector<int>> data;
    int N;

    Grid(int size) {
        N = size;
        data = vector<vector<int>>(N, vector<int>(N, 0));
    }

    // Return a new Grid that is a 90-degree rotation of this one
    Grid Rotate90() const {
        Grid rotatedGrid(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                rotatedGrid.data[j][N - 1 - i] = data[i][j];
        return rotatedGrid;
    }

    // Return a new Grid that is the Y-axis reflection of this one
    Grid Reflection() const {
        Grid reflectedGrid(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                reflectedGrid.data[i][N - 1 - j] = data[i][j];
        return reflectedGrid;
    }

    void LoadFromInput() {
        char ch;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                cin >> ch;
                data[i][j] = (ch == '@') ? 1 : 0;
            }
    }

    void Print() const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << (data[i][j] ? '@' : '-');
            }
            cout << '\n';
        }
    }

    void SetData(const vector<vector<int>>& newData) {
        data = newData;
    }

    // Compare this grid with another
    bool Equals(const Grid& other) const {
        return data == other.data;
    }
};


int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int N;
    cin >> N;
    Grid baseGrid(N);
    baseGrid.LoadFromInput();

    // Example usage:
    Grid transGrid(N);
    transGrid.LoadFromInput();

    if(baseGrid.Rotate90().Equals(transGrid)) {
        cout << 1 << '\n';
    }
    else if(baseGrid.Rotate90().Rotate90().Equals(transGrid)) {
        cout << 2 << '\n';
    }
    else if(baseGrid.Rotate90().Rotate90().Rotate90().Equals(transGrid)) {
        cout << 3 << '\n';
    }
    else if(baseGrid.Reflection().Equals(transGrid)) {
        cout << 4 << '\n';
    }
    else if(baseGrid.Reflection().Rotate90().Equals(transGrid)) {
        cout << 5 << '\n';
    }
    else if(baseGrid.Reflection().Rotate90().Rotate90().Equals(transGrid)) {
        cout << 5 << '\n';
    }
    else if(baseGrid.Reflection().Rotate90().Rotate90().Rotate90().Equals(transGrid)) {
        cout << 5 << '\n';
    }
    else if(baseGrid.Equals(transGrid)){
        cout << 6 << '\n';
    }
    else {
        cout << 7 << '\n';
    }

    return 0;
}
