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

string str;
int b;
bool visited[11];
int maxans = 0;

void func(string temp){
    if(temp.length() == str.length() && stoi(temp) < b){
        maxans = max(maxans, stoi(temp));
        return;
    }

    for(int i = 0; i < str.length(); i++){
        if(!visited[i]){
            visited[i] = 1;
            func(temp + str[i]);
            visited[i] = 0;
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str >> b;

    for(int i = 0; i < str.length(); i++){
        if(str[i] != '0'){
            string temp = "";
            temp += str[i];
            visited[i] = 1;
            func(temp);
            visited[i] = 0;
        }
    }

    if(maxans == 0){
        cout << -1;
    }
    else{
        cout << maxans;
    }
	return 0;
}