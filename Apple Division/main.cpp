#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> weights(n);
    long long totalSum = 0;
    
    // Read the weights and calculate the total sum
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
        totalSum += weights[i];
    }
    
    long long minDifference = totalSum;  // Initialize the minimum difference with the largest possible value
    
    // There are 2^n possible subsets, so we try all possible bitmask subsets
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long subsetSum = 0;
        
        // For the current bitmask, compute the sum of the subset
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subsetSum += weights[i];
            }
        }
        
        // Calculate the difference between the two group sums
        long long otherGroupSum = totalSum - subsetSum;
        long long diff = abs(subsetSum - otherGroupSum);
        
        // Update the minimum difference
        minDifference = min(minDifference, diff);
    }
    
    // Output the result
    cout << minDifference << endl;

    return 0;
}
