#include <iostream>
#include <vector>

using namespace std;

void dfs_perm(vector<int>& nums, vector<bool>& visited, vector<int>& paths, vector<vector<int>>& res) {
    if(paths.size()==nums.size()) {
        res.push_back(paths); //Foudn complete permutation
    }

    for(int i=0;i<nums.size();i++) {
        if (!visited[i]){ //Skip over visited paths
            visited[i] = true;
            paths.push_back(nums[i]);
            dfs_perm(nums, visited, paths, res);
            /* When permuation traversal is complete, backtrack to current branch*/
            paths.pop_back();
            visited[i]=false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    dfs_perm(nums, used, path, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    cout << "Permutations:\n";
    for (const auto& p : permutations) {
        for (int x : p) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}