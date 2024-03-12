#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int prime[1000001];



int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= m; i++){
        prime[i] = i;
    }

    for(int i = 2; i <= sqrt(m); i++){
        if(prime[i] == 0){
            continue;
        }
        for(int j = i * i; j <= m; j += i){
            prime[j] = 0;
        }
    }

    for(int i = n; i <= m; i++){
        if(prime[i] > 0){
            cout << i << '\n';
        }
    }
    return 0;
}