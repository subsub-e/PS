#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x; cin >> x;
    long long s = 1;
    long long e = 1;
    int flag = 0;
    while(1){
        if((e * e - s * s) == x){
            cout << e << '\n';
            flag = 1;
        }
        if((e * e - s * s) > x && e - s == 1){
            break;
        }
        if((e * e - s * s) > x){
            s++;
        }
        else{
            e++;
        }
    }
    if(flag == 0){
        cout << -1;
    }
}