#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int cards[1000006];
int scores[1000006];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    vector<int> v;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        cards[x] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = v[i] * 2; j < 1000001; j += v[i]){
            if(cards[j] == 1){
                scores[v[i]]++;
                scores[j]--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << scores[v[i]] << ' ';
    }

}