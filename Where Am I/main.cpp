#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);

    int N; string s; cin >> N >> s;

    for(int K=1;K<N;K++){
        set<string> set;
        for(int i=0;i+K<=N;i++){
            set.insert(
                s.substr(i,K)
            );
        }
        int length_of_set=set.size();
        int length_for_uniqueness=N-K+1; //Set will only have unique elements so the maximum possible number of substrings of size K defines a unique set
        if(length_of_set==length_for_uniqueness){
            cout << K << '\n';
            return 0;
        }
    }
}