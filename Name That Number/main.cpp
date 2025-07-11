/*
ID: aditya_10
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    string num;
    cin >> num;

    ifstream dict("dict.txt");
    vector<string> dict_words;
    string w;
    while (dict >> w) {
        dict_words.push_back(w);
    }

    unordered_map<char, char> letter_to_digit = {
        {'A','2'},{'B','2'},{'C','2'},
        {'D','3'},{'E','3'},{'F','3'},
        {'G','4'},{'H','4'},{'I','4'},
        {'J','5'},{'K','5'},{'L','5'},
        {'M','6'},{'N','6'},{'O','6'},
        {'P','7'},{'R','7'},{'S','7'},
        {'T','8'},{'U','8'},{'V','8'},
        {'W','9'},{'X','9'},{'Y','9'}
    };

    bool found = false;
    for (const string& word : dict_words) {
        if (word.size() != num.size())
            continue;

        bool match = true;
        for (int i = 0; i < word.size(); ++i) {
            if (letter_to_digit[word[i]] != num[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << word << endl;
            found = true;
        }
    }

    if (!found)
        cout << "NONE" << endl;
}
