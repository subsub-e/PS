#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<string> v;
bool visited[26];
int maxans = 0;

void func(int x, int cnt){
    if(cnt == m){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int flag = 0;
            for(int j = 0; j < v[i].length(); j++){
                if(visited[(int) v[i][j] - 97] == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cnt++;
            }
        }
        maxans = max(maxans, cnt);
        return;
    }


    for(int i = x; i < 26; i++){
        if(!visited[i]){
            visited[i] = 1;
            func(i, cnt + 1);
            visited[i] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
	
    if(m < 5){
        cout << 0;
        return 0;
    }
    if(m == 26){
        cout << n;
        return 0;
    }

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        v.push_back(str);
    }

    m -= 5;
    
    visited[0] = 1;
    visited[2] = 1;
    visited[8] = 1;
    visited[13] = 1;
    visited[19] = 1;
    
    func(0, 0);
    cout << maxans;

	return 0;
}