#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    unordered_map<string, vector<string>> m;
    unordered_map<string, string> group;
    for(int i = 0; i < n; i++){
        string str;
        int a;
        cin >> str >> a;
        for(int j = 0; j < a; j++){
            string member;
            cin >> member;
            m[str].push_back(member);
            group[member] = str;
        }
    }

    for(int i = 0; i < k; i++){
        string str;
        int p;
        cin >> str >> p;
        if(p == 1){
            cout << group[str] << '\n';
        }
        else{
            vector<string> ans(m[str]);
            sort(ans.begin(), ans.end());
            for(int j = 0; j < ans.size(); j++){
                cout << ans[j] << '\n';
            }
        }
    }
}