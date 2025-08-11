#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word; cin >> word;

    sort(word.begin(),word.end());

    int count=0;

    do{
        count++;
    }while(next_permutation(word.begin(),word.end()));

    cout << count << '\n';

    do{
        cout << word << '\n';
    }while(next_permutation(word.begin(),word.end()));
}