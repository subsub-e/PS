#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int n, k, sum;

int func(int x){
    int cnt = 0;
    while(x > 0){
        if(x % 2 == 1){
            cnt++;
        }
        x /= 2;
    }
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


    cin >> n >> k;
    if(n <= k){
        cout << 0;
    }
    else{
        while(1){
            int temp = func(n);
            if(temp <= k){
                break;
            }
            sum++;
            n++;
        }
        cout << sum;
    }  
    
    
	return 0;
}