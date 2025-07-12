/*
ID: aditya_10
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <vector>

using namespace std;

bool numberInVector(vector<int> nums, int number) {
    if (number == 0) return false;
    while (number > 0) {
        int digit = number % 10;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == digit) {
                found = true;
                break;
            }
        }
        if (!found) return false;
        number /= 10;
    }
    return true;
}

int main() {
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);

    int N; cin >> N;

    vector<int> nums(N);

    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    int numTop=0; //Top with 3 digits
    int numBottom=0; //Bottom with 2 digits

    int partial1, partial2, total;

    int count=0;

    for(int a=0;a<N;a++)
    for(int b=0;b<N;b++)
    for(int c=0;c<N;c++){
        numTop =nums[a]*100+nums[b]*10+nums[c];
        if (numTop < 100) continue;
        for(int d=0;d<N;d++)
        for(int e=0;e<N;e++){
            numBottom=nums[d]*10+nums[e];



            partial1 = numTop*nums[e];
            partial2 = numTop*nums[d];
            total = numTop*numBottom;

            if(partial1 < 100 || partial1 > 999) continue;
            if(partial2 < 100 || partial2 > 999) continue;
            if(total < 1000 || total > 9999) continue;

            if(
                numberInVector(nums,partial1) &&
                numberInVector(nums,partial2) &&
                numberInVector(nums,total)
            ){
                count++;
            }
        }
    }
    cout << count << endl;
}