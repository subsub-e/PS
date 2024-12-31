#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    while(1){
        int n, m;
        vector<int> v;
        cin >> n >> m;
        if(cin.eof()){
            break;
        }
        n *= 10000000;
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        int st = 0;
        int en = v.size() - 1;
        long long sum = 0;
        int temp = 0;
    
        while(st < en){
            sum = v[st] + v[en];
            if(sum == n){
                temp = 1;
                break;
            }
            if(sum < n){
                st++;
            }
            else{
                en--;
            }
        }
        if(temp == 0){
            cout << "danger" << '\n';
        }
        else{
            cout << "yes " << v[st] << ' ' << v[en] << '\n'; 
        }
    }
}