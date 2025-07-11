#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);

    int N, Q; cin >> N >> Q;

    vector<int> prefix1(N+1, 0), prefix2(N+1, 0), prefix3(N+1);

    for(int i=1;i<=N;i++) {
        int breed; cin >> breed;
        prefix1[i]=prefix1[i-1];
        prefix2[i]=prefix2[i-1];
        prefix3[i]=prefix3[i-1];

        if(breed==1) prefix1[i]++;
        else if(breed==2) prefix2[i]++;
        else if(breed==3) prefix3[i]++;
    }

    for(int q=0;q<Q;q++) {
        int a, b; cin >> a >> b;
        int count1 = prefix1[b] - prefix1[a-1];
        int count2 = prefix2[b] - prefix2[a-1];
        int count3 = prefix3[b] - prefix3[a-1];

        cout << count1 << " " << count2 << " " << count3 << endl;
    }
}