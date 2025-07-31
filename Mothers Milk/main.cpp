/*
ID: aditya_10
LANG: C++
TASK: milk3
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[21][21][21]; // Maximum capacity is 20, so we use 21
set<int> results;
int A, B, C;

void dfs(int a, int b, int c) {
    if (visited[a][b][c])
        return;

    visited[a][b][c] = true;

    if (a == 0)
        results.insert(c);

    // Pour from one bucket to another
    int capacities[3] = {A, B, C};
    int current[3] = {a, b, c};

    for (int from = 0; from < 3; ++from) {
        for (int to = 0; to < 3; ++to) {
            if (from == to || current[from] == 0 || current[to] == capacities[to])
                continue;

            int pour_amount = min(current[from], capacities[to] - current[to]);

            int next[3] = {current[0], current[1], current[2]};
            next[from] -= pour_amount;
            next[to] += pour_amount;

            dfs(next[0], next[1], next[2]);
        }
    }
}

int main() {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin >> A >> B >> C;

    dfs(0, 0, C);

    vector<int> answer(results.begin(), results.end());
    for (size_t i = 0; i < answer.size(); ++i) {
        if (i > 0) fout << " ";
        fout << answer[i];
    }
    fout << endl;

    return 0;
}
