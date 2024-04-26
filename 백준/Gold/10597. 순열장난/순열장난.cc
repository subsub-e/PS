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
vector<int> v;
bool visited[51];
int maxans;
int flag = 0;

void func(int depth){
    if(depth > str.length() || flag == 1){
        return;
    }
    if(depth == str.length()){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        flag = 1;
        return;
    }

    

    int temp = stoi(str.substr(depth, 1));
    int temp1 = stoi(str.substr(depth, 2));

    if(!visited[temp] && 0 < temp && temp <= maxans){
        visited[temp] = 1;
        v.push_back(temp);
        func(depth + 1);
        v.pop_back();
        visited[temp] = 0;
    }

    if(!visited[temp1] && 0 < temp1 && temp1 <= maxans){
        visited[temp1] = 1;
        v.push_back(temp1);
        func(depth + 2);
        v.pop_back();
        visited[temp1] = 0;
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
    int temp = str.length() - 9;
    if(temp < 0){
        maxans = str.length();
    }
    else{
        maxans = 9 + temp / 2;
    }
    func(0);

	return 0;
}