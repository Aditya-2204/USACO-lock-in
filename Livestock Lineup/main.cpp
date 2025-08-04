#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> pairs;

void permute(vector<int> current, int size=8){
    if(current.size()==size){
        //Process permutation
        bool accepted=false;
        for(auto& pair : pairs ){
            accepted=false;
            //Cycle through list
            bool temp_accepted=false
            for(int i=0;i<7;i++){
                if((current[i]==pair.first && current[i+1]==pair.second) ||
                   (current[i]==pair.second && current[i+1]==pair.first)) {
                    temp_accepted=true;
                    break
                   }
                if(i==6){
                    if(temp_accepted==true){
                        accepted=true;
                    }
                    else{
                        accepted=false;
                    }
                }
            }
        }
    }
}

int main(){
    int N; cin >> N;
    for(int i=0;i<N;i++){
        string a,w,x,y,z,b; cin >> a >> w >> x >> y >> z >> b;
        if(a=="Bessie"){
            pairs[i].first=0;
        }
        if(b=="Bessie"){
            pairs[i].second=0;
        }
        if(a=="Buttercup"){
            pairs[i].first=1;
        }
        if(b=="Buttercup"){
            pairs[i].second=1;
        }
        if(a=="Belinda"){
            pairs[i].first=2;
        }
        if(a=="Belinda"){
            pairs[i].first=2;
        }
        if(a=="Beatrice"){
            pairs[i].first=3;
        }
        if(a=="Beatrice"){
            pairs[i].first=3;
        }
        if(a=="Bella"){
            pairs[i].first=4;;
        }
        if(a=="Bella"){
            pairs[i].first=4;
        }
        if(a=="Blue"){
            pairs[i].first=5;
        }
        if(a=="Blue"){
            pairs[i].first=5;
        }
        if(a=="Betsy"){
            pairs[i].first=6;
        }
        if(a=="Betsy"){
            pairs[i].first=6;
        }
        if(a=="Sue"){
            pairs[i].first=7;
        }
        if(a=="Sue"){
            pairs[i].first=7;
        }
    }
}