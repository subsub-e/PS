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
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    int start_time = 60 * stoi(str1.substr(0, 2)) + stoi(str1.substr(3));
    int end_time = 60 * stoi(str2.substr(0, 2)) + stoi(str2.substr(3));
    int exit_time = 60 * stoi(str3.substr(0, 2)) + stoi(str3.substr(3));

    //cout << start_time << ' ' << end_time << ' ' << exit_time;
    unordered_set<string> s;
    int cnt = 0;
    string str, name;
    while(cin >> str >> name){
        int t = 60 * stoi(str.substr(0, 2)) + stoi(str.substr(3));

        if(t <= start_time){
            s.insert(name);
        }
        else if(t >= end_time && t <= exit_time){
            if(s.find(name) != s.end()){
                cnt++;
                s.erase(name);
            }
        }
    }
    cout << cnt;
}