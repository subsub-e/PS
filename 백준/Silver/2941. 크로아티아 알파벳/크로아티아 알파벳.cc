#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(i >= 2 && str[i] == '='){
            if(str[i-2] == 'd' && str[i-1] == 'z'){
                cnt-=1;
                continue;
            }
        }
        if(i >= 1 && str[i] == '='){
            if(str[i-1] == 'c' || str[i-1] == 's' || str[i-1] == 'z'){
                continue;
            }
        }
        if(i >= 1 && str[i] == '-'){
            if(str[i-1] == 'c' || str[i-1] == 'd'){
                continue;
            }
        }
        if(i >= 1 && str[i] == 'j'){
            if(str[i-1] == 'l' || str[i-1] == 'n'){
                continue;
            }
        }
        cnt++;
    }
    cout << cnt;
	return 0;
}