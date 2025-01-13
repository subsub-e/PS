#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<pair<int, int> > v;

long double solution(int x1, int x2){
    long double a = v[0].first;
    long double b = v[0].second;
    long double c = v[x1].first;
    long double d = v[x1].second;
    long double e = v[x2].first;
    long double f = v[x2].second;

    return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    long double ans = 0;

    for(int i = 1; i < n-1; i++){
        ans += solution(i, i + 1);
    }

    cout << fixed;
    cout.precision(1);

    cout << abs(ans);

}