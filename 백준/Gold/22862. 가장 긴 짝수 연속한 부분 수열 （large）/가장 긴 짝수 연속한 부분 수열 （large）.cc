#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int visited[100001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int st = 0;
    int maxans = 0;
    int cnt = 0;

    for(int en = 0; en < n; en++){
        if(v[en] % 2 == 1){
            cnt++;
        }
        if(cnt > m){
            maxans = max(maxans, en - st - m);
            //cout << maxans << ' ' << en << '\n';
            while(cnt > m && st < en){
                if(v[st] % 2 == 1){
                    cnt--;
                    st++;
                }
                else{
                    st++;
                    continue;
                }
            }
            //cout << st << ' ' << en << '\n';
        }
    }
    //cout << cnt << '\n';
    maxans = max(maxans, n - st - cnt);
    cout << maxans;
}