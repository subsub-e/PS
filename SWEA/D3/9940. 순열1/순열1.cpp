#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
using namespace std;

bool visited[100001];

int main(int argc, char** argv)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;
    

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(visited, 0, sizeof(visited));
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            visited[x] = 1;
        }

        int flag = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << '#' << test_case << ' ' << "Yes" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "No" << '\n';
        }
    }
    return 0;
}