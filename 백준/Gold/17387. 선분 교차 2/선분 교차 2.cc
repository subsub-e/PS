#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

pair<ll, ll> x1;
pair<ll, ll> x2;
pair<ll, ll> y3;
pair<ll, ll> y2;

bool isLine(ll t1, ll t2, ll t3, ll t4){
    if(t1 > t2){
        swap(t1, t2);
    }
    if(t3 > t4){
        swap(t3, t4);
    }

    return (t1 <= t4 && t2 >= t3);
}

ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    pair<ll, ll> ca;
    pair<ll, ll> ab;
    ca.first = a.first - c.first;
    ca.second = a.second - c.second;
    ab.first = b.first - a.first;
    ab.second = b.second - a.second;

    if(ca.first * ab.second - ca.second * ab.first < 0){
        return -1;
    }
    else if(ca.first * ab.second - ca.second * ab.first == 0){
        return 0;
    }
    else{
        return 1;
    }
}

bool solution(){
    ll z1 = ccw(x1, x2, y3);
    ll z2 = ccw(x1, x2, y2);
    ll z3 = ccw(y3, y2, x1);
    ll z4 = ccw(y3, y2, x2);

    if(z1 * z2 == 0 && z3 * z4 == 0){
        return isLine(x1.first, x2.first, y3.first, y2.first) && isLine(x1.second, x2.second, y3.second, y2.second);
    }

    return z1 * z2 <= 0 && z3 * z4 <= 0;
}   

int main(){
    cin >> x1.first >> x1.second >> x2.first >> x2.second >> y3.first >> y3.second >> y2.first >> y2.second;

    cout << solution();

}