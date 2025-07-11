#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

struct Cow {
    int x, y, id;
};

int compute_area(const vector<Cow>& cows, const set<int>& removed) {
    int min_x = 40001, max_x = 0;
    int min_y = 40001, max_y = 0;

    for (const Cow& cow : cows) {
        if (removed.count(cow.id)) continue;
        min_x = min(min_x, cow.x);
        max_x = max(max_x, cow.x);
        min_y = min(min_y, cow.y);
        max_y = max(max_y, cow.y);
    }
    return (max_x - min_x) * (max_y - min_y);
}

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    int N;
    fin >> N;
    vector<Cow> cows(N);

    for (int i = 0; i < N; ++i) {
        fin >> cows[i].x >> cows[i].y;
        cows[i].id = i;
    }

    vector<Cow> by_x = cows, by_y = cows;
    sort(by_x.begin(), by_x.end(), [](Cow a, Cow b) { return a.x < b.x; });
    sort(by_y.begin(), by_y.end(), [](Cow a, Cow b) { return a.y < b.y; });

    // Collect candidates: top 10 in each extreme
    set<int> candidate_ids;
    for (int i = 0; i < 10 && i < N; ++i) {
        candidate_ids.insert(by_x[i].id);
        candidate_ids.insert(by_x[N - 1 - i].id);
        candidate_ids.insert(by_y[i].id);
        candidate_ids.insert(by_y[N - 1 - i].id);
    }

    vector<int> candidates(candidate_ids.begin(), candidate_ids.end());
    int ans = compute_area(cows, {});

    // Try all combinations of removing 0 to 3 cows from candidates
    int csize = candidates.size();
    for (int i = 0; i < csize; ++i) {
        for (int j = i; j < csize; ++j) {
            for (int k = j; k < csize; ++k) {
                set<int> removed = {candidates[i]};
                if (j != i) removed.insert(candidates[j]);
                if (k != i && k != j) removed.insert(candidates[k]);
                ans = min(ans, compute_area(cows, removed));
            }
        }
    }

    fout << ans << endl;
    return 0;
}
