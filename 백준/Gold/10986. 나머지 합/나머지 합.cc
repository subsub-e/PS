#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[1001];

int main(){
    cin >> n >> m;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        sum += x;
        arr[sum % m]++;
    }

    long long ans = 0;
    for(int i = 0; i <= m; i++){
        ans += (arr[i] * (arr[i] - 1) / 2);
    }

    cout << arr[0] + ans;
}