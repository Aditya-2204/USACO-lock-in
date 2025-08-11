#include <iostream>
#include <vector>

using namespace std;

vector<int> capacity(3);
vector<int> amount(3);

int TURN_MAX=100;

int main(){
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);

    for(int i=0;i<3;i++){
        cin >> capacity[i] >> amount[i];
    }

    for(int i=0;i<TURN_MAX;i++){
        int bucket_no_before=i%3;
        int bucket_no_after=(i+1)%3;

        int amt = min(amount[bucket_no_before],capacity[bucket_no_after]-amount[bucket_no_after]);

        amount[bucket_no_before]-=amt;
        amount[bucket_no_after]+=amt;
    }
    for(auto milk : amount) {
        cout << milk << '\n';
    }
}