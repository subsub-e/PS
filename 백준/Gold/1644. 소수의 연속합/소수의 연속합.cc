#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
int n;

void IsPrime(int x){
    vector<bool> prime(x + 1, true);

    for(int i = 2; i * i <= x; i++){
        if(prime[i]){
            for(int j = i * i; j <= x; j += i){
                prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= x; i++){
        if(prime[i]){
            v.push_back(i);
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    IsPrime(n);

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << ' ';
    // }

    int cnt = 0;
    int en = 0;
    int sum = 0;

    for(int st = 0; st < v.size(); st++){
        while(en < v.size()){
            if(sum == n){
                //cout << st << ' ' << en << '\n';
                cnt++;
                break;
            }
            if(sum > n){
                break;
            }
            sum += v[en];
            en++;
        }
        sum -= v[st];
    }
    if(v[v.size() - 1] == n){
        cnt++;
    }
    cout << cnt;
}