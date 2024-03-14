#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }

    return gcd(y, x % y);
}

long long func(long long a, long long b){
    long long temp = gcd(a, b);

    long long sum = temp * (a / temp) * (b / temp);
    return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    while(n--){
        long long a, b;
        cin >> a >> b;
        cout << func(a, b) << '\n';
    }

	return 0;
}