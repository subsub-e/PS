#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int palin(int left, int right, string str, int d){
    while(left < right){
        if(str[left] != str[right]){
            if(d == 0){
                if(palin(left + 1, right, str, 1) == 0 || palin(left, right - 1, str, 1) == 0){
                    return 1;
                }
                else{
                    return 2;
                }
            }
            else{
                return 2;
            }
        }
        else{
            left++;
            right--;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        string str; cin >> str;
        cout << palin(0, str.length() - 1, str, 0) << '\n';
    }
}