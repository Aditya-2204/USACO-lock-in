#include <iostream>
#include <vector>

using namespace std;

void search(vector<int>& curr, vector<bool>& used, vector<int>& cows, int N, int& count){
    if(curr.size()==cows.size()){
        count++;
        return;
    }

    for(int i=0;i<N;i++){
        if(used[i]) continue;
        if(!curr.empty() && cows[i] == curr.back()) continue;
        used[i]=true;
        curr.push_back(cows[i]);
        search(curr,used,cows,N,count);
        //Undo
        curr.pop_back();
        used[i]=false;
    }
}

int main(){
    int N; cin >> N;
    vector<int> cows(N);

    for(int i=0;i<N;i++){
        cin >> cows[i];
    }

    vector<bool> used(N,false);
    vector<int> curr;

    int count=0;
    search(curr,used,cows,N,count);

    cout << count << '\n';
}