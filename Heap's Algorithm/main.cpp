#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapPermutation(vector<int>& vec, int k) {
    if (k == 1) {
        // Print the current permutation
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < k; i++) {
        heapPermutation(vec, k - 1);

        // Swap elements based on whether k is even or odd
        if (k % 2 == 0) {
            swap(vec[i], vec[k - 1]);
        } else {
            swap(vec[0], vec[k - 1]);
        }
    }
}

int main() {
    vector<int> vec = {1, 2, 3};
    heapPermutation(vec, vec.size());
    return 0;
}