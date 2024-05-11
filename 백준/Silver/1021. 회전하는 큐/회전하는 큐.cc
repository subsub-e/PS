#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> dq;
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    int cnt = 0;
    while(m--){
        int x; cin >> x;
        
        int left, right;
        for(int i = 0; i < dq.size(); i++){
            if(dq[i] == x){
                left = i;
                right = dq.size() - left - 1;
                break;
            }
        }

        if(left <= right){
            while(1){
                if(dq.front() == x){
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        else{
            while(1){
                if(dq.front() == x){
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }

    cout << cnt;
    return 0;
}