#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> v;
char arr[4] = {'2', '3', '5', '7'};

bool isPrime(int n){
    for(int i = 2; i < n / 2 + 1; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void func(string str){
    if(str.length() == n){
        cout << str << '\n';
        return;
    }

    for(int i = 0; i < 10; i++){
        string temp = str + to_string(i);
        //cout << temp << '\n';
        if(isPrime(stoi(temp))){
            func(temp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> n;
    if(n == 1){
        cout << 2 << '\n' << 3 << '\n' << 5 << '\n' << 7 << '\n';
        return 0;
    }
    //cout << "sss" + to_string(2) << '\n';
    for(int i = 0; i < 4; i++){
        string str = "";
        str += arr[i];
        func(str);
    }


	return 0;
}