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

int visited[27];
string str;
int cnt;

void func(int now, string temp){
    //cout << temp << '\n';
    if(now == str.length()){
        cnt++;
        //cout << temp << '\n';
        return;
    }

    for(int i = 0; i < 26; i++){
        //cout << (int) temp[temp.length() - 1] - 'a' << '\n';
        if(visited[i] == 0){
            continue;
        }
        if(temp != "" && (int) temp[temp.length() - 1] - 'a' == i){
            continue;
        }
        visited[i]--;
        //cout << char(i + 'a') << '\n';
        func(now + 1, temp + (char) (i + 'a'));
        visited[i]++;
        
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

    for(int i = 0; i < str.length(); i++){
        visited[str[i] - 'a']++;
    }

    func(0, "");

    cout << cnt;

	return 0;
}