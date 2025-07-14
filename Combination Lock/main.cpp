/*
ID: aditya_10
LANG: C++
TASK: combo
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int wrap(int x, int N) {
    if (x < 1) return x+N;
    if (x > N) return x-N;
    return x;
}

int main() {

    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);


    int N; cin >> N;
    int fj[3]; int m[3];

    for(int i=0;i<3;i++) cin >> fj[i];
    for(int i=0;i<3;i++) cin >> m[i];

    set<tuple<int, int, int>> set;

    for(int a=-2;a<3;a++){
        for(int b=-2;b<3;b++){
            for(int c=-2;c<3;c++) {
                set.insert({wrap(m[0]+a,N), wrap(m[1]+b,N), wrap(m[2]+c,N)});
            }
        }
    }


    for(int a=-2;a<3;a++){
        for(int b=-2;b<3;b++){
            for(int c=-2;c<3;c++) {
                set.insert({wrap(fj[0]+a,N), wrap(fj[1]+b,N), wrap(fj[2]+c,N)});
            }
        }
    }

    cout << set.size() << endl;
}