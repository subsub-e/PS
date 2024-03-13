#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
#define MAX 10000001


bool arr[MAX];
long long cnt = 0;
long long n, m;

void prime(){
    for(int i = 2; i < MAX; i++){
        arr[i] = true;
    }
    for(int i = 2; i * i <= MAX; i++){
        if(arr[i]){
            for(int j = i * i; j < MAX; j += i){
                arr[j] = false;
            }
        }
    }
}

void func(){
    for(int i = 2; i <= MAX; i++){
        if(arr[i]){
            long long num = i;
            while(num <= m / i){
                if(n <= num * i){
                    cnt++;
                }
                num *= i;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    cin >> n >> m;
    prime();
    func();
    cout << cnt;
	return 0;
}