/*
ID: aditya_10
TASK: beads
LANG: C++
*/

/*
ID: aditya_10
TASK: beads
LANG: C++
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);

    int N;
    cin >> N;

    string s;
    cin >> s;

    s += s; // Duplicate string for wrap-around

    int maxCount = 0;

    for(int i = 0; i < N; i++) {
        // Count right
        int right = 0;
        char rightColor = '\0';
        int j = i + 1;

        while (right < N) {
            char c = s[j];
            if (c != 'w') {
                if (rightColor == '\0')
                    rightColor = c;
                else if (c != rightColor)
                    break;
            }
            right++;
            j++;
        }

        // Count left
        int left = 0;
        char leftColor = '\0';
        j = i + N; // This is CRUCIAL
        while (left < N - right) { // avoid double-counting
            char c = s[j];
            if (c != 'w') {
                if (leftColor == '\0')
                    leftColor = c;
                else if (c != leftColor)
                    break;
            }
            left++;
            j--;
        }

        int total = left + right;
        total = min(total, N);

        maxCount = max(maxCount, total);
    }

    cout << maxCount << endl;
    return 0;
}
