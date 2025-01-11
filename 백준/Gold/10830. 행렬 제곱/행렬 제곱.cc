#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, b;
long long a[5][5];
long long temp[5][5];
long long ans[5][5];

void func(long long x[5][5], long long y[5][5]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = 0;
            for(int k = 0; k < n; k++){
                temp[i][j] += x[i][k] * y[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            x[i][j] = temp[i][j];
        }
    }
}

int main(){
    cin >> n >> b;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
        ans[i][i] = 1; 
    }

    while(b > 0){
        if(b % 2 == 1){
            func(ans, a);
        }
        func(a, a);
        b /= 2;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }


}