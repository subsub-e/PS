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

int n;
char arr[10];
vector<int> v;
bool visited[10];
long long maxans = 0;
string minans = "9876543210";
vector<int> max_v;
vector<int> min_v;
string max_ans;
string min_ans;

void func(int x , int cnt){
    if(v.size() == n + 1){
        
        string str = "";
        for(int i = 0; i < n + 1; i++){
            str += to_string(v[i]);
        }
        if(maxans < stoll(str)){
            maxans = stoll(str);
            max_ans = str;
        }
        if(stoll(minans) >= stoll(str)){
            minans = str;
            min_ans = str;
        }
    }


    for(int i = 0; i < 10; i++){
        if(visited[i]){
            continue;
        }
        if(arr[cnt - 1] == '<'){
            if(v[cnt - 1] > i){
                continue;
            }
        }
        if(arr[cnt - 1] == '>'){
            if(v[cnt - 1] < i){
                continue;
            }
        }

        visited[i] = 1;
        v.push_back(i);
        func(i, cnt + 1);
        v.pop_back();
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < 10; i++){
        visited[i] = 1;
        v.push_back(i);
        func(i, 1);
        visited[i] = 0;
        v.pop_back();
    }

    cout << max_ans << '\n' << min_ans;

	return 0;
}