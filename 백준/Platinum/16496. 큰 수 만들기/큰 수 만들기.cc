#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

int n;
vector<string> v;

bool comp(string a, string b){
    if(a == b){
        return false;
    }
    string temp1 = a + b;
    string temp2 = b + a;
    if(temp1 > temp2){
        return true;
    }
    else{
        return false;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int flag = 0;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        if(x != "0"){
            flag = 1;
        }
        v.push_back(x);
    }
    if(flag == 0){
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    string str = "";
    for(int i = 0; i < v.size(); i++){
        str += v[i];
    }
    cout << str;
	return 0;
}