#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);

    int N; cin >> N;
    map<string, int>cows;
    string cow_names[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

    for(int i=0;i<7;i++){
        cows[cow_names[i]]=0;
    }

    
    for(int i=0;i<N;i++){
        string cow; int amt;
        cin >> cow >> amt;

        cows[cow]+=amt;
    }
    vector<int> milk_amounts;
    for(auto& [key, value] : cows){
        milk_amounts.push_back(value);
    }

    milk_amounts.erase(unique(milk_amounts.begin(), milk_amounts.end()), milk_amounts.end());
    sort(milk_amounts.begin(),milk_amounts.end());

    int second_smallest=milk_amounts[1];

    vector<string> candidates;
    for(auto& [key, value] : cows){
        if(value==second_smallest){
            candidates.push_back(key);
        }
    }

    if(candidates.size()>1){
        cout<<"Tie"<<'\n';
    }
    else{
        cout<<candidates[0]<<'\n';
    }

}