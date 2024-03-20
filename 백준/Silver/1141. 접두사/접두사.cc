#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    vector<string> v;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        int flag = 0;
        for(int j = i + 1; j < v.size(); j++){
            if(v[i].length() <= v[j].length()){
                //cout << v[i] << ' ' << v[j].substr(0, v[i].length()) << '\n';
                if(v[i] == v[j].substr(0, v[i].length())){
                    flag = 1;
                }
            }
        }
        if(flag == 0){
            cnt++;
        }
    }

    int flag = 0;
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] != v[i + 1]){
            flag = 1;
        }
    }

    if(flag == 0){
        cout << 1;
        return 0;
    }

    cout << cnt;
	return 0;
}