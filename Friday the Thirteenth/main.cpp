/*
ID: aditya_10
TASK: friday
LANG: C++
*/

#include <iostream>

using namespace std;

int main() {
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);

    int N; cin >> N;

    int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int count[7] = {0};

    int startWeekDay = 2; // Monday

    for(int yr=1900; yr<1900+N; yr++) {
        for(int month=0; month<12; month++) {
            int weekDay13th = (startWeekDay + 12) % 7;
            count[weekDay13th]++;

            int days = month_days[month];
            if(month == 1 && (yr % 4 ==0 && (yr % 100 != 0 || yr % 400 ==0))) {
                days = 29;
            }

            // Correct variable name
            startWeekDay = (startWeekDay + days) % 7;
        }
    }


    for (int i = 0; i < 7; i++) {
        cout << count[i];
        if (i != 6) cout << " ";
    }
    cout << endl;
    return 0;
}
