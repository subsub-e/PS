#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long n, p, q;
unordered_map<long long, long long> m;

long long solve(long long ans){
    if(ans == 0){
        return 1;
    }

    if(m.find(ans) != m.end()){
        return m[ans];
    }

    long long ret = solve(ans / p) + solve(ans / q);
    m[ans] = ret;

    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> p >> q;
    m[0] = 1;
    cout << solve(n);
}