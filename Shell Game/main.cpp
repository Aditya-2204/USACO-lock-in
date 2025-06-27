#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int n;

    fin >> n;

    int hasBall[3] = {0, 0, 0};
    for(int j=0;j<3;j++){
        int point=0;
        hasBall[j]=1;
        for(int i=0;i<n;i++){
            int a,b,g;
            fin >> a >> b >> g;

            swap(hasBall[a-1], hasBall[b-1]);

            if(hasBall[g-1]==1){
                point++;
            }
        }
        cout << point << endl;
        hasBall[j]=0;
    }
}