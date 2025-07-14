#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int N;
    cin >> N;

    vector<tuple<int, string, int>> events;
    for (int i = 0; i < N; i++) {
        int day, change;
        string name;
        cin >> day >> name >> change;
        events.push_back({day, name, change});
    }

    sort(events.begin(), events.end());

    map<string, int> milk = {
        {"Bessie", 7},
        {"Elsie", 7},
        {"Mildred", 7}
    };

    set<string> prevLeaders = {"Bessie", "Elsie", "Mildred"};
    int countChanges = 0;

    for (auto &[day, name, delta] : events) {
        milk[name] += delta;

        int maxMilk = max({milk["Bessie"], milk["Elsie"], milk["Mildred"]});
        set<string> currLeaders;
        for (auto &[cow, amount] : milk) {
            if (amount == maxMilk) currLeaders.insert(cow);
        }

        if (currLeaders != prevLeaders) {
            countChanges++;
            prevLeaders = currLeaders;
        }
    }

    cout << countChanges << endl;
}
