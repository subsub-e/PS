#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <vector>
#include <string>
using namespace std;

int minans = INT_MAX;
int n, m;
int len;
set<int> s;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x; cin >> x;
        s.insert(x);
    }

    int index = 0;

    while(index < 1000000){
        string temp = to_string(index);
        int flag = 0;
        for(int i = 0; i < temp.length(); i++){
            if(s.find((int) temp[i] - 48) != s.end()){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            //cout << index << '\n';
            if(index > n){
                minans = min(minans, index - n + (int) temp.length());
            }
            else{
                minans = min(minans, n - index + (int) temp.length());
            }
        }
        index++;
    }

    
    if(n > 100){
        minans = min(minans, n - 100);
    }
    else{
        minans = min(minans, 100 - n);
    }
    

    cout << minans;

    return 0;
}