#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using ll = long long;


using namespace std;

int main(){
    int N; cin >> N;

    map<ll,long long> quant;

    for(int i=0;i<N;i++){
        long long ci;cin>>ci;
        if(!quant.count(ci)){ /*If tuition doesn't exist*/
            quant[ci]=1;
        } else {
            quant[ci]++;
        }
    }

    vector<long long> keys;
    vector<long long> values;

    for(auto& pair : quant){
        int key = pair.first;
        int value = pair.second;

        keys.push_back(key);
        values.push_back(value);
    }

    reverse(keys.begin(), keys.end());
    reverse(values.begin(), values.end());

    //prefix sum
    for(int i=1;i<values.size();i++){
        values[i]+=values[i-1];
    }

    long long best_return=0; long long best_charge=1e9;
    for(int i=0;i<values.size();i++){
        long long key=keys[i];
        long long value=values[i];

        if(key*value >= best_return){
            best_return=key*value;
            if(key <= best_charge){
                best_charge=key;
            }
        }
    }

    cout << best_return << " " << best_charge << '\n';

}