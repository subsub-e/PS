#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<long long, long long> m;
long long n;


long long dp(long long x){
    if(m[x]){
        return m[x];
    }

    long long result;

    if(x % 2 == 0){
        result = (dp(x / 2) * (2 * dp(x / 2 - 1) + dp(x / 2))) % 1000000007;
    }
    else{
        result = ((dp((x + 1) / 2) * dp((x + 1) / 2) % 1000000007) + (dp((x - 1) / 2) * dp((x - 1) / 2) % 1000000007) % 1000000007);
    }

    return m[x] = result % 1000000007;
}


int main(){
    cin >> n;

    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    m[3] = 2;

    cout << dp(n);
}