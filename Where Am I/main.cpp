#include <iostream>
#include <unordered_map>
#include <string>



using namespace std;

int main(){
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);

    

    int N; cin >> N;
    string sequence; cin >> sequence;

    for(int sublen=1;sublen<=N;sublen++){
        unordered_map<string, int> stringMap;
        bool accepted=true;
        for(int i=0;i<N-sublen+1;i++){
            string sub = sequence.substr(i,sublen);
            stringMap[sub]++; //Increase the substring count storage by 1
            if(stringMap[sub]>1) accepted=false;
        }
        if(accepted){
            cout << sublen << endl;
            break;
        }
    }
}