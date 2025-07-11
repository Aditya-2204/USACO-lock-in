/*
ID: aditya_10
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;

int main() {
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);

    int N; cin >> N;

    vector<pii> tIntervals(N);
    for(int i=0;i<N;i++) {
        cin >> tIntervals[i].first >> tIntervals[i].second;
    }

    sort(tIntervals.begin(), tIntervals.end());

    vector<pii> merged;
    merged.push_back(tIntervals[0]);

    for(int i=1;i<N;i++) {
        auto& last = merged.back();
        if(tIntervals[i].first <= last.second) {
            last.second = max(last.second, tIntervals[i].second);
        } else {
            merged.push_back(tIntervals[i]);
        }
    }

    int maxTimeC=0;
    for(auto& i : merged) {
        maxTimeC = max(maxTimeC, i.second - i.first);
    }

    int maxTimeI=0;
    for(int i=0;i<merged.size()-1;i++) {
        int idleTime = merged[i+1].first - merged[i].second;
        maxTimeI = max(maxTimeI, idleTime);
    }

    cout << maxTimeC << " " << maxTimeI << endl;
}
