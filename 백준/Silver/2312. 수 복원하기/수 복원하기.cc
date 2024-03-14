#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int arr[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for(int i = 2; i <= 100000; i++){
        arr[i] = i;
    }

    for(int i = 2; i <= sqrt(100000); i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i * i; j <= 100000; j+=i){
            arr[j] = 0;
        }
    }
    vector<int> prime;
    for(int i = 2; i <= 100000; i++){
        if(arr[i] != 0){
            prime.push_back(i);
        }
    }

    int n; cin >> n;
    
    while(n--){
        int m; cin >> m;
        vector<pair<int, int> > v;

        int index = 0;
        int cnt = 0;
        while(m > 1){
            if(m % prime[index] == 0){
                cnt++;
                m /= prime[index];
            }
            else{
                if(cnt > 0){
                    v.push_back(make_pair(prime[index], cnt));
                    cnt = 0;
                }
                index++;
            }
        }
        
        if(cnt > 0){
            v.push_back(make_pair(prime[index], cnt));
        }
        for(int i = 0; i < v.size(); i++){
            cout << v[i].first << ' ' << v[i].second << '\n';
        }
    }


	return 0;
}