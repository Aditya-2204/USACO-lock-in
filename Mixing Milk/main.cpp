/*
ID: aditya_10
LANG: C++
TASK: milk
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int total_units, num_farmers;
    cin >> total_units >> num_farmers;

    vector<pair<int, int>> farmers(num_farmers);
    for (int i = 0; i < num_farmers; i++) {
        cin >> farmers[i].first >> farmers[i].second;
    }

    // Sort farmers by price ascending
    sort(farmers.begin(), farmers.end());

    int total_price = 0;
    int units_needed = total_units;

    for (const auto& farmer : farmers) {
        int buy = min(units_needed, farmer.second);
        total_price += buy * farmer.first;
        units_needed -= buy;
        if (units_needed == 0)
            break;
    }

    cout << total_price << endl;
}
