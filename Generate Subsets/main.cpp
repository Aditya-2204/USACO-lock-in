#include <iostream>
#include <vector>

using namespace std;

void search(vector<bool>& toAdd, vector<int>& arr, int idx=0){
    if(idx==arr.size()){
        for(int i=0;i<toAdd.size();i++){
            if(toAdd[i]){
                cout << arr[i] << " ";
            }
            
        }
        cout << "\n";
        return;
    }
    
    toAdd.push_back(true);
    search(toAdd, arr, idx+1);
    toAdd.pop_back();

    toAdd.push_back(false);
    search(toAdd, arr, idx+1);
    toAdd.pop_back();

}

int main(){
    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    vector<bool> toAdd;

    search(toAdd,arr);
}