#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N=3;

void processLine(int& individuals, int& teams, vector<string>& strings){
    for(string s : strings){
        set<char> se(s.begin(),s.end());
        if(se.size()==1){
            individuals++;
        }
        if(se.size()==2){
            teams++;
        }
    }
}

int main(){
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);

    char board[N][N];
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
        cin >> board[i][j];
    }

    int individuals=0;
    int teams=0;

    vector<string> strings(3+3+2);

    strings[0] = {board[0][0], board[0][1], board[0][2]}; //Rows
    strings[1] = {board[1][0], board[1][1], board[1][2]};
    strings[2] = {board[2][0], board[2][1], board[2][2]};

    strings[3] = {board[0][0], board[1][0], board[2][0]}; //Columns
    strings[4] = {board[0][1], board[1][1], board[2][1]};
    strings[5] = {board[0][2], board[1][2], board[2][2]};

    strings[6] = {board[0][0], board[1][1],board[2][2]}; //Rows
    strings[7] = {board[2][0], board[1][1], board[0][2]};

    processLine(individuals,teams,strings);

    cout << individuals << '\n' << teams << '\n';
}