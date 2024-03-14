#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int y = 0;
    int m = 0;
    int d = 0;

    int cnt = 0;

    for(int i = 0; i < 1000000; i++){
        if(y == a && b == m && c == d){
            cout << cnt;
            return 0;
        }
        y = (y + 1) % 16;
        m = (m + 1) % 29;
        d = (d + 1) % 20;
        if(y % 16 == 0){
            y = 1;
        }
        if(m % 29 == 0){
            m = 1;
        }
        if(d % 20 == 0){
            d = 1;
        }
        //cout << y << ' ' << m << ' ' << d << '\n';
        cnt++;
    }
    
	return 0;
}