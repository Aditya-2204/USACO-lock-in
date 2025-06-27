#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; 
    cin >> n;

    vector<pair<char,int>> constraints;
    for(int i=0;i<n;i++){
        char p; int c;
        cin >> p >> c;
        constraints.push_back({p,c});
    }

    // Generate candidate positions to test
    vector<int> positions;
    for(auto &pr : constraints){
        positions.push_back(pr.second);
        positions.push_back(pr.second - 1);
        positions.push_back(pr.second + 1);
    }

    // Remove duplicates
    sort(positions.begin(), positions.end());
    positions.erase(unique(positions.begin(), positions.end()), positions.end());

    int minLiars = n;

    for(int pos : positions){
        if(pos < 0 || pos > 1e9) continue; //Remove any illegal values

        int liars = 0;
        for(auto &pr : constraints){
            if(pr.first == 'G'){
                if(pos < pr.second) liars++; //If the currently viewed sample position is less than location even when it says 'greater than', increase liar by 1.
            }
            if(pr.first == 'L'){
                if(pos > pr.second) liars++;
            }
        }
        minLiars = min(minLiars, liars);
    }

    cout << minLiars << endl;
}
