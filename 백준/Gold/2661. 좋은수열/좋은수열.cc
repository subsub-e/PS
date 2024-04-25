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

vector<int> v;
int n;

void func(string str, int now){
    for(int i = 2; i <= now / 2; i++){
        string str1 = str.substr(now - i * 2, i);
        string str2 = str.substr(now - i);
        //cout << now << ' ' << str1 << ' ' << str2 << '\n';
        if(str1 == str2){
            return;
        }
    }

    if(str.length() == n){
        cout << str;
        exit(0);
    }


    for(int i = 1; i <= 3; i++){
        if(i == (int) str[now - 1] - '0'){
            continue;
        }
        if(i == 1){
            func(str + "1", now + 1);
        }
        if(i == 2){
            func(str + "2", now + 1);
        }
        if(i == 3){
            func(str + "3", now + 1);
        }
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    func("", 0);





	return 0;
}