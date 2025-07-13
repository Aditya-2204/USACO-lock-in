#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int manhattanDist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);

    int N;
    cin >> N;

    vector<pair<int,int>> points(N);
    for(int i=0;i<N;i++){
        cin >> points[i].first >> points[i].second;
    }

    // Compute all consecutive distances and total distance
    vector<int> segDist(N-1);
    int totalDistance = 0;
    for(int i=1;i<N;i++){
        segDist[i-1] = manhattanDist(points[i], points[i-1]);
        totalDistance += segDist[i-1];
    }

    // Compute the maximum saving from skipping a checkpoint
    int maxSaving = 0;
    for(int k=1;k<N-1;k++){
        int saving = segDist[k-1] + segDist[k] - manhattanDist(points[k-1], points[k+1]);
        maxSaving = max(saving, maxSaving);
    }

    int minDistance = totalDistance - maxSaving;
    cout << minDistance << endl;
}
