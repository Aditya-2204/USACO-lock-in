/*
ID: aditya_10
LANG: C++
TASK: wormhole
*/

#include <iostream>

int n;
int x[20] , y[20], next_wormhole[20], part[20], answer=0;
bool paired[20];

using namespace std;

bool check(){
    for (int start = 1; start <= n; ++start) {
        int pos = start;
        for (int steps = 0; steps < n; ++steps) {
            pos = next_wormhole[part[pos]];
            if (pos == 0) break; // Reached end of line
        }
        if (pos != 0) return true; // Cycle detected
    }
    return false;
}

void dfs() {
    int f = 1;
    while(paired[f] && f<=n) f++;
    if(f == n+1){
        if(check()) answer++;
    } //check
    for(int s=f+1;s<=n;s++) {
        if(!paired[s]) {
            paired[f] = paired[s] = true;
            part[f] = s, part[s] = f;
            dfs();
            paired[f] = paired[s] = false;
            part[f] =part[s] = 0;
        }
    }
}

int main(){
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
        next_wormhole[i]=0;
        paired[i]=0;
    }

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) if(i!=j && y[i]==y[j] && x[j] >= x[i] && (!next_wormhole[i] || x[j]<x[next_wormhole[i]])) {
        next_wormhole[i]=j;
    }
    
    dfs();

    cout << answer << endl;

}