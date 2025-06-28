#include <iostream>
#include <vector>
 
// round u to the nearest d
int round (int u, int d) {
    if (u % d < d/2) {
        return u - u % d;
    }
    return u + d - u % d;
}
 
//chain round u to the nearest target
int chain_round(int u, int target){
    for(int ten = 10; ten<=target; ten *= 10){
        u = round(u, ten);
    }
    return u;
}
 
int main () {
    const int maxN = 1'000'000;
    std::vector<int> ans(maxN+1);
    ans[1] = 0;
    for(int N = 2; N <= maxN; N++){
        int V = ans[N-1];
        int target = 1;
        while(target < N){
            target *= 10;
        }
        if(chain_round(N, target) != round(N, target)){
            V++;
        }
        ans[N] = V;
    }
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N;
        std::cout << ans[N] << "\n";
    }
}