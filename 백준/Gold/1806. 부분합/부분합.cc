#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;


int n, s;
vector<int> v;
int answer = 1e9 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int st = 0;
    int en = 0;
    int sum = 0;
    while(en < v.size()){
        while(st <= en && sum + v[en] >= s){
            sum -= v[st];
            answer = min(answer, en - st + 1);
            //cout << en - st + 1 << '\n';
            st++;
        }
        sum += v[en];
        en++;
        //cout << st << ' ' << en << ' ' << sum << '\n';
    }
    if(answer == 1e9 + 10){
        cout << 0;
    }
    else{
        cout << answer;
    }
    return 0;
}
