#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);

    int M,N,K;cin >> M >> N >> K;

    vector<string> letters(M);
    // Read each row as a string of N characters
    for (int i = 0; i < M; i++) {
        cin >> letters[i];
    }

    for(int i=0;i<M;i++){
        for(int vertical=0;vertical<K;vertical++){
            for(int j=0;j<N;j++){
                for(int horizontal=0;horizontal<K;horizontal++){
                    cout << letters[i][j];
                }
            }
            cout << '\n';
        }
    }

}