#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(stdin);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<string> zodiacs = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    map<string, int> zodiac_to_idx;
    for(int i=0;i<12;i++){
        zodiac_to_idx[zodiacs[i]]=i;
    }

    map<string, int> cow_to_year;
    cow_to_year["Bessie"] = 0;  // Bessie's birth year = 0

    for(int i=0;i<N;i++){
        string new_cow, dummy, direction, zodiac, dummy2, dummy3, ref_cow;
        cin >> new_cow >> dummy >> dummy >> direction >> zodiac >> dummy2 >> dummy3 >> ref_cow;

        int ref_year = cow_to_year[ref_cow];
        int target_idx = zodiac_to_idx[zodiac];
        int offset;
        if(direction=="previous"){
            offset = (ref_year - target_idx) % 12;
            if(offset<=0) offset += 12;
            cow_to_year[new_cow]=ref_year-offset;
        } else {
            offset = (target_idx - ref_year) % 12;
            if(offset <= 0) offset+=12;
            cow_to_year[new_cow] = ref_year + offset;
        }
    }

    cout << abs(cow_to_year["Elsie"] - cow_to_year["Bessie"]) << '\n';
}