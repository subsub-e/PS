#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;


int n, t;

bool comp(string a, string b){
    return (int) a.length() < (int) b.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--){
        vector<string> v;
        unordered_set<string> s;
        int flag = 0;
        cin >> t;
        for(int i = 0; i < t; i++){
            string str; cin >> str;
            v.push_back(str);
        }
        sort(v.begin(), v.end(), comp);
        
        for(int i = 0; i < t; i++){
            if(flag == 1){
                break;
            }
            if(s.empty()){
                s.insert(v[i]);
            }
            else{
                for(int j = 1; j <= 10; j++){
                    //cout << v[i].substr(0, j) << '\n';
                    if(j >= (int) v[i].length()){
                        break;
                    }
                    if(s.find(v[i].substr(0, j)) != s.end()){
                        cout << "NO" << '\n';
                        flag = 1;
                        break;
                    }
                }
                s.insert(v[i]);
            }
        }
        if(flag == 0){
            cout << "YES" << '\n';
        }
    }
}