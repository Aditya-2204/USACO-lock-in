#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Returns patch positions for one breed
vector<int> optimal_spaces(const string& species, char species_type, int K) {
    vector<int> positions;
    int N = species.size();

    // Collect all positions of cows of species_type
    for (int i = 0; i < N; i++) {
        if (species[i] == species_type) {
            positions.push_back(i);
        }
    }

    vector<int> patches;
    int i = 0;
    int n = (int)positions.size();

    while (i < n) {
        // Start from leftmost uncovered cow
        int start = positions[i];

        // Place patch as far right as possible covering this cow
        int patch_pos = start + K;
        if (patch_pos >= N) patch_pos = N - 1;  // Clamp to max position

        // Move i forward to cover all cows within patch coverage
        int coverage_right = patch_pos + K;
        while (i < n && positions[i] <= coverage_right) {
            i++;
        }

        patches.push_back(patch_pos);
    }

    return patches;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        string species; cin >> species;

        // Get patch positions for G and H
        vector<int> g_patches = optimal_spaces(species, 'G', K);
        vector<int> h_patches = optimal_spaces(species, 'H', K);

        // Construct output string
        string result(N, '.');

        // Place G patches
        for (int pos : g_patches) {
            result[pos] = 'G';
        }
        // Place H patches
        for (int pos : h_patches) {
            // Check for conflicts (optional, can ignore if none)
            if (result[pos] == '.') {
                result[pos] = 'H';
            } else if (result[pos] == 'G') {
                // Conflict - unlikely, but if happens, try shifting patch by 1 left or right if possible
                if (pos > 0 && result[pos - 1] == '.') {
                    result[pos - 1] = 'H';
                } else if (pos < N - 1 && result[pos + 1] == '.') {
                    result[pos + 1] = 'H';
                } else {
                    // No place to shift - keep G (problem states any valid config accepted)
                }
            }
        }

        int total_patches = (int)g_patches.size() + (int)h_patches.size();

        cout << total_patches << '\n' << result << '\n';
    }

    return 0;
}
