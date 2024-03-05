#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        multiset<long long> ms;
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            char c;
            long long x;
            cin >> c >> x;
            if(c == 'I'){
                ms.insert(x);
            }
            else{
                if(ms.size() == 0){
                    continue;
                }
                if(x == 1){
                    auto it = ms.end();
                    auto it_prev = prev(it);
                    ms.erase(it_prev);   
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }

        if(ms.size() == 0){
            cout << "EMPTY" << '\n';
        }
        else{
            auto it1 = ms.begin();
            auto it2 = ms.end();
            auto it_prev2 = prev(it2);
            cout << *it_prev2 << ' ' << *it1 << '\n';
        }
    }
}