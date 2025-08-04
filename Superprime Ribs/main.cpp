/*
ID: aditya_10
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

using namespace std;

int primeList[4] = {1,3,7,9};
int prime[4] = {2,3,5,7};
vector<int> ans;

void generate_sprimes(int digits, int N, int n){
    if(digits==N) {
        ans.push_back(n);
    }
    for(auto& prime : primeList) {
        int new_n = 10*n + prime;
        if(isPrime(new_n)) generate_sprimes(digits+1,N,new_n);
    }
}

int main(){
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);

    int N; cin>>N;

    for(auto& num : prime){
        generate_sprimes(1,N,num);
    }

    for(auto& i : ans){
        cout << i << '\n';
    }
    
}