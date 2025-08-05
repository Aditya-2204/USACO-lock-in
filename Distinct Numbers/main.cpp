#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> nums(N);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    int count=1;
    for(int i=0;i<N-1;i++){
        if(nums[i+1] != nums[i]){
            count++;
        }
    }

    cout << count << '\n';
}