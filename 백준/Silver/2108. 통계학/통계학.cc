#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int visited[8001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    double n; cin >> n;
    double sum = 0;
    int minans = 4001;
    int maxans = -4001;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        visited[x + 4000]++;
        sum += x;
        maxans = max(maxans, x);
        minans = min(minans, x);
    }

    sort(v.begin(), v.end());

    int max_temp = 0;
    for(int i = 0; i < 8001; i++){
        max_temp = max(max_temp, visited[i]);
    }


    int cnt = 0;
    for(int i = 0; i < 8001; i++){
        if(max_temp == visited[i]){
            cnt++;
        }
    }

    int ans;
    
    if(cnt > 1){
        int flag = 0;
        for(int i = 0; i < 8001; i++){
            if(flag == 1 && max_temp == visited[i]){
                ans = i;
                break;
            }
            if(max_temp == visited[i]){
                flag = 1;
            }
        }
    }
    else if(cnt == 1){
        for(int i = 0; i < 8001; i++){
            if(max_temp == visited[i]){
                ans = i;
                break;
            }
        }
    }

    ans -= 4000;
    if(round(sum / n) == -0){
        cout << 0 << '\n';
    }
    else{
        cout << round(sum / n) << '\n';
    }
    cout << v[n / 2] << '\n';
    if(n == 1){
        cout << v[0] << '\n';
    }
    else{
        cout << ans << '\n';
    }   
    cout << maxans - minans;
   
	return 0;
}