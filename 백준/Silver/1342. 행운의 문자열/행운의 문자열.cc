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

int visited[26];
bool visited2[26];
string str;
int cnt;

void func(string temp){
    //cout << temp << '\n';
    if(temp.length() == str.length()){
        cnt++;
        //cout << temp << '\n';
        return;
    }

    for(int i = 0; i < 26; i++){
        //cout << (int) temp[temp.length() - 1] - 'a' << '\n';
        if(visited[i] > 0 && (int) temp[temp.length() - 1] - 'a' != i){
            visited[i]--;
            //cout << char(i + 'a') << '\n';
            func(temp + char(i + 'a'));
            visited[i]++;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
    for(int i = 0; i < str.length(); i++){
        visited[(int) str[i] - 'a']++;
    }
    for(int i = 0; i < str.length(); i++){
        if(!visited2[(int) str[i] - 'a']){
            string temp = "";
            temp += str[i];
            visited2[(int) str[i] - 'a'] = 1;
            visited[(int) str[i] - 'a']--;
            func(temp);
            visited[(int) str[i] - 'a']++;
        }
    }

    cout << cnt;

	return 0;
}