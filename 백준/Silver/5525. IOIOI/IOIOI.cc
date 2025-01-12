#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, ans;
string str;

int main(){
    cin >> n >> m >> str;
    string target = "IOI";

    for(int i = 2; i <= n; i++){
        target += "OI";
    }

    for(int i = 0; i <= str.length() - target.length(); i++){
        if(str.substr(i, target.length()) == target){
            //cout << str.substr(i, target.length()) << '\n';
            ans++;
        }
    }
    cout << ans;
}