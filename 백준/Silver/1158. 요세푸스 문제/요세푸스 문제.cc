#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    cout << '<';
    int index = 1;
    while(q.size() > 1){
        if(index % m == 0){
            cout << q.front() << ", ";
            q.pop();
            index++;
            continue;
        }
        q.push(q.front());
        q.pop();
        index++;
    }
    cout << q.front() << '>';
}