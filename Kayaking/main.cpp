#include <iostream>
#include <climits>

using namespace std;

#define all(x) x.begin(), x.end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<int> weights(2*N);

    for(int i=0;i<2*N;i++){
        cin >> weights[i];
    }

    sort(all(weights));

    int tandemK = N-1;


    vector<int> weightDiff;

    for(int i=0;i<weights.size()-1;i++){
        weightDiff.push_back(weights[i+1]-weights[i]);
    }

    sort(all(weightDiff));

    int minTotalInstability=0;
    int i=0;
    for(auto& weightD : weightDiff){
        if((weightD!=0) && (i<tandemK)){
            minTotalInstability+=weightD;
            i++;
        }
        else break;
    }

    cout << minTotalInstability << '\n';
}