#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

bool visited[21];
string str;

void dfs(string temp, int x){
    if(x == str.length() - 1){
        cout << temp << '\n';
        return;
    }

    for(int i = x; i < str.length(); i++){
        if (i != x && temp[i] == temp[x])
			continue;
        //if(temp[i] != temp[x]){
            char c = temp[i];
            temp[i] = temp[x];
            temp[x] = c;
        //}
        dfs(temp, x + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        cin >> str;
        memset(visited, 0, sizeof(visited));
        sort(str.begin(), str.end());
        dfs(str, 0);
    }
    return 0;
}