#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v1.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        v2.push_back(x);
    }

    int flag = 0;
    int v1_max, v1_index, v2_max, v2_index;

    while(1){
        while(1){
            if(v1.empty() || v2.empty()){
                flag = 1;
                break;
            }

            v1_max = *max_element(v1.begin(), v1.end());
            v1_index = max_element(v1.begin(), v1.end()) - v1.begin();
            v2_max = *max_element(v2.begin(), v2.end());
            v2_index = max_element(v2.begin(), v2.end()) - v2.begin();

            if(v1_max == v2_max){
                break;
            }
            else if(v1_max > v2_max){
                v1.erase(v1.begin() + v1_index);
            }
            else{
                v2.erase(v2.begin() + v2_index);
            }
        }
        if(flag == 1){
            break;
        }
        ans.push_back(v1_max);
        int temp = 0;

        for(int i = v1_index + 1; i < v1.size(); i++){
            v1[temp++] = v1[i];
        }
        for(int i = 0; i <= v1_index; i++){
            v1.pop_back();
        }
        temp = 0;

        for(int i = v2_index + 1; i < v2.size(); i++){
            v2[temp++] = v2[i];
        }
        for(int i = 0; i <= v2_index; i++){
            v2.pop_back();
        }

    }

    if(ans.size() == 0){
        cout << 0;
    }
    else{
        cout << ans.size() << '\n';
        for(auto x : ans){
            cout << x << ' ';
        }
    }

    return 0;
}