#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    int n, m;
    fin >> n >> m;

    int limit[100] = {0};   // Speed limit for each of the 100 miles
    int bessie[100] = {0};  // Bessie's speed for each mile

    int pos = 0;
    for (int i = 0; i < n; i++) {
        int dist, speed;
        fin >> dist >> speed;
        for (int j = 0; j < dist; j++) {
            limit[pos++] = speed;
        }
    }

    pos = 0;
    for (int i = 0; i < m; i++) {
        int dist, speed;
        fin >> dist >> speed;
        for (int j = 0; j < dist; j++) {
            bessie[pos++] = speed;
        }
    }

    int maxSpeedDiff = 0;
    for (int i = 0; i < 100; i++) {
        maxSpeedDiff = max(maxSpeedDiff, bessie[i] - limit[i]);
    }

    fout << max(0, maxSpeedDiff) << endl;

    return 0;
}
