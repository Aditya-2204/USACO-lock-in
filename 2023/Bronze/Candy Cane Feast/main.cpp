#include <iostream>
#include <vector>

using namespace std;

int height_boost(int candy_cane_height, int candy_cane_elevation, int cow_height) {
    int drop = candy_cane_elevation-candy_cane_height;
    return max(0, cow_height-drop);
} 

int main(){
    int N, M; cin >> N >> M;
    vector<int> heightOfCows(N);
    vector<int> heightOfCandyCanes(M);

    for(int i=0;i<N;i++){
        cin >> heightOfCows[i];
    }
    for(int i=0;i<M;i++){
        cin >> heightOfCandyCanes[i];
    }

    for(int i=0;i<M;i++) {
        int elevation = heightOfCandyCanes[i];
        for(int j=0;j<N;j++){
            int change = height_boost(heightOfCandyCanes[i],elevation,heightOfCows[j]);
            heightOfCandyCanes[i]-=change;
            heightOfCows[j]+=change;
        }
    }

    for(auto& cow: heightOfCows) {
        cout << cow << endl;
    }
}