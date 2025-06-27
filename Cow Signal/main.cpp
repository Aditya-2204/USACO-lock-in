#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");

    int h, w, f;
    fin >> h >> w >> f;

    string line;
    for (int i = 0; i < h; i++) {
        fin >> line;
        
        string scaled_line;
        for(int j=0;j<w;j++){
            scaled_line.append(f, line[j]);
        }
        for(int k=0;k<f;k++){fout << scaled_line << endl;} //Print line twice
    }

    return 0;
}
