#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("shell.in","r",stdin);
    freopen("shell.out","w",stdout);



    int N; cin >> N;
    vector<int> shells(3,0);
    vector<pair<pair<int,int>,int>> swaps(N); //(a,b,g)
    for(int i=0;i<N;i++){
        cin >> swaps[i].first.first >> swaps[i].first.second >> swaps[i].second;
        swaps[i].first.first--;
        swaps[i].first.second--;
        swaps[i].second--;
    }
    int score=0;
    for(int i=0;i<3;i++){
        int t_score=0;
        shells[i]=1;
        for(int j=0;j<N;j++){ //Swapping time - simulation round
            int a=swaps[j].first.first;
            int b=swaps[j].first.second;
            int g=swaps[j].second;
            swap(shells[a],shells[b]);
            if(shells[g]==1) t_score++;

        }
        score=max(score,t_score);
        shells[0]=0; //Reset for next possibe swap
        shells[1]=0;
        shells[2]=0;
        
    }
    cout << score << '\n';
    return 0;
}