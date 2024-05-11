#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                if(pq.top().second == 1){
                    cout << -pq.top().first << '\n';
                }
                else{
                    cout << pq.top().first << '\n';
                }
                pq.pop();
            }
        }
        else{
            if(x > 0){
                pq.push(make_pair(x, 2));
            }
            else{
                pq.push(make_pair(-x, 1));
            }
        }
    }

    return 0;
}