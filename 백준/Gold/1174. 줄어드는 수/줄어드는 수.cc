#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
using namespace std;


int n;


string func(){
    queue<pair<string, int> > q;
    for(int i = 0; i < 10; i++){
        q.push(make_pair(to_string(i), i));
    }

    int cnt = 1;
    while(!q.empty()){
        string temp = q.front().first;
        int x = q.front().second;
        q.pop();

        if(cnt == n){
            return temp;
        }
        if(cnt > 10000){
            break;
        }

        for(int i = 0; i < x; i++){
            q.push(make_pair(temp + to_string(i), i));
        }
        cnt++;
    }
    return "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    cout << func();
    return 0;
}