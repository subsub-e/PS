#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;
    sort(str.rbegin(), str.rend());
    long long sum = 0;
    for(int i = 0; i < str.length() - 1; i++){
        sum += (int) str[i];
    }
    if(sum % 3 == 0 && str[str.length()-1] == '0'){
        cout << str;
    }
    else{
        cout << -1;
    }
	return 0;
}