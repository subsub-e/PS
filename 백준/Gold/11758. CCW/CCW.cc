#include <iostream>
#include <vector>


using namespace std;

pair<int, int> x;
pair<int, int> y;
pair<int, int> z;



int main(){
    cin >> x.first >> x.second >> y.first >> y.second >> z.first >> z.second;

    pair<int, int> ca;
    pair<int, int> ab;

    ca.first = x.first - z.first;
    ca.second = x.second - z.second;
    ab.first = y.first - x.first;
    ab.second = y.second - x.second;

    if(ca.first * ab.second - ca.second * ab.first < 0){
        cout << -1;
    }
    else if(ca.first * ab.second - ca.second * ab.first > 0){
        cout << 1;
    }
    else{
        cout << 0;
    }
}