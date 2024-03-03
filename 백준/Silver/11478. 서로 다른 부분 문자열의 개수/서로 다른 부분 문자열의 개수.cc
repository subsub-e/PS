#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    unordered_set<string> s;

    for(int i = 0; i < str.length(); i++){
        string temp = "";
        for(int j = i; j < str.length(); j++){
            temp += str[j];
            s.insert(temp);
        }
    }

    int cnt = 0;
    for(auto u : s){
        cnt++;
        //cout << u << '\n';
    }
    cout << cnt;
}