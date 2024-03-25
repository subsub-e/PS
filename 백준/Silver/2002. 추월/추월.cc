#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_map<string, int> m1;
    vector<int> v;

    for(int i = 0; i < n; i++){
        string str; cin >>str;
        m1[str] = i;
    }
    for(int i = 0; i < n; i++){
        string str; cin >>str;
        v.push_back(m1[str]);
    }

    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] > v[j]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}