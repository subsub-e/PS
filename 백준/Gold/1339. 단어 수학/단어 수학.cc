#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int n;
string str1, str2;
vector<string> v;
unordered_map<char, int> m;
vector<pair<int, char> > v2;
unordered_map<char, int> dict;

bool comp(string strA, string strB){
    return strA.length() > strB.length();
}

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < v.size(); i++){
        int temp = 1;
        int index = v[i].length() - 1;
        while(index >= 0){
            m[v[i][index]] += temp;
            temp *= 10;
            index--;
        }
    }

    for(auto now : m){
        v2.push_back(make_pair(now.second, now.first));
    }

    sort(v2.rbegin(), v2.rend());

    int t = 9;

    for(int i = 0; i < v2.size(); i++){
        dict[v2[i].second] = t--;
    }

    int ans = 0;

    for(int i = 0; i < v.size(); i++){
        int temp = 0;
        for(int j = 0; j < v[i].length(); j++){
            temp += dict[v[i][j]] * pow(10, v[i].length() - 1 - j);
        }
        ans += temp;
    }

    cout << ans;
}