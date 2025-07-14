/*
ID: aditya_10
LANG: C++
TASK
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);

    int N; cin >> N;
    vector<int> shuffleSequence(N);
    vector<int> ids(N);

    for(int i=0;i<N;i++){
        int seq; cin >> seq;
        shuffleSequence[i]=seq-1;
    }

    for(int i=0;i<N;i++){
        cin >> ids[i];
    }



    for(int i=0;i<3;i++){
        vector<int> newSequence(N);
        for(int j=0;j<N;j++) {
            newSequence[j]=ids[shuffleSequence[j]];
        }
        ids=newSequence;
    }



    for(int i=0;i<N;i++){
        cout << ids[i] << endl;
    }
}