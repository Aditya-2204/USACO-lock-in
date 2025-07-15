/*
ID: aditya_10
LANG: C++
TASK: combo
*/

#include <iostream>
using namespace std;

int main() {
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);

    int N;
    cin >> N;
    int fj[3], m[3];

    for(int i=0;i<3;i++) cin >> fj[i];
    for(int i=0;i<3;i++) cin >> m[i];

    auto is_close = [&](int a, int b) {
        int diff = abs(a-b);
        return diff <=2 || diff >= N-2;
    };

    int total =0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                bool close_fj = is_close(i,fj[0]) && is_close(j,fj[1]) && is_close(k,fj[2]);
                bool close_m = is_close(i,m[0]) && is_close(j,m[1]) && is_close(k,m[2]);
                if(close_fj || close_m)
                    total++;
            }
        }
    }
    cout<<total<<endl;
}
