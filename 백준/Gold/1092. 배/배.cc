#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<int> crain;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        crain.push_back(x);
    }
    int m;
    vector<int> box;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        box.push_back(x);
    }
    
    sort(crain.rbegin(), crain.rend());
    sort(box.rbegin(), box.rend());

    int t = 0;

    while(1){
        if(box.empty()){
            cout << t;
            return 0;
        }
        if(crain[0] < box[0]){
            cout << -1;
            return 0;
        }
        t++;
        int index = 0;
        for(int i = 0; i < crain.size(); i++){
            if(box.empty()){
                cout << t;
                return 0;
            }
            if(index >= box.size()){
                break;
            }
            if(crain[i] >= box[index]){
                box.erase(box.begin() + index);
                //box.pop_back();
                //cout << index << ' ' << t << '\n';
                // for(int i = 0; i < box.size(); i++){
                //     cout << box[i] << ' ';
                // }
                // cout << '\n';
            }
            else{
                while(index < box.size()){
                    index++;
                    if(crain[i] >= box[index]){
                        box.erase(box.begin() + index);
                        // cout << index << ' ' << t << '\n';
                        // for(int i = 0; i < box.size(); i++){
                        //     cout << box[i] << ' ';
                        // }
                        // cout << '\n';
                        break;
                    }
                }
            }
        }
        
    }

    cout << t;
	return 0;
}