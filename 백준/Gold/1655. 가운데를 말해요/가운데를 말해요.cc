#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int> > minq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(maxq.size() == minq.size()){
            maxq.push(x);
        }
        else{
            minq.push(x);
        }

        if(!maxq.empty() && !minq.empty() && maxq.top() > minq.top()){
            int temp1 = maxq.top();
            int temp2 = minq.top();
            maxq.pop();
            minq.pop();
            maxq.push(temp2);
            minq.push(temp1);
        }

        cout << maxq.top() << '\n';
    }
}