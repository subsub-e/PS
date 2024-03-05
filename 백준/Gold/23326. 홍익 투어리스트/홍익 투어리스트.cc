#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    map<int, int> m;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x){
            m[i] = x;
        }
    }

    int index = 0;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        if(x == 3){
            if(m.size() == 0){
                cout << -1 << '\n';
            }
            else{
                auto now = m.lower_bound(index);
                if(now == m.end()){
                    int step = (n - index) + (*m.begin()).first;
                    cout << step << '\n';
                }
                else{
                    int step = (*now).first - index;
                    cout << step << '\n';
                }
            }
        }
        else if(x == 1){
            int y; cin >> y;
            y--;
            if(m[y]){
                m.erase(y);
            }
            else{
                m[y] = 1;
            }
        }
        else if(x == 2){
            int y; cin >> y;
            index = (index + y) % n;
        }
    }
}