#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin >> v[i];

    int mx = *max_element(v.begin(), v.end());

    if(k==1){
        if(v[j-1]==mx){
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "YES";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
