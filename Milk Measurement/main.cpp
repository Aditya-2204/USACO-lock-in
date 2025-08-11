#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int,int>

using namespace std;

int main(){
    int N,T;cin>>N>>T;
    vector<pii> weights(N);
    for(int i=0;i<N;i++){
        cin>>weights[i].first>>weights[i].second;
    }

    sort(weights.begin(),weights.end());

    
}