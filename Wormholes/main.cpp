/*
ID: aditya_10
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);

    map<int, set<int>> wormholes; //X and Y

    int N; cin >> N;

    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        wormholes[y].insert(x);
    }
    int c=0;
    for(auto& [y, x_set] : wormholes) {
        if (x_set.size() > 1) {
            auto prev = x_set.begin();
            auto it = std::next(prev);
            for (; it != x_set.end(); ++it, ++prev) {
                c += *it - *prev - 1;
            }
        }
    }
    cout << c << endl;
}