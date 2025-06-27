/*
ID: aditya_10
LANG: C++
TASK: test
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int maxSum=0;

    for(int a=0;a*x<=m;a++){
        int b = (m-x*a)/y;
        int sum = a*x+b*y;
        if(sum <=m && sum > maxSum){
            maxSum=sum;
        }
    }

    cout << maxSum;

    
}