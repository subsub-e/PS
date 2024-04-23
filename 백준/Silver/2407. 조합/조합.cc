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

string arr[101][101];



string bigadd(string a, string b){

    int sum = 0;
    string result;

    while(!a.empty() || !b.empty() || sum){
        if(!a.empty()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}


string combination(int n, int m){
    if(m == 0 || n == m){
        return "1";
    }

    string &result = arr[n][m];

    if(result != ""){
        return result;
    }

    result = bigadd(combination(n-1, m-1), combination(n-1, m));

    return result;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    int n, m;
    cin >> n >> m;
    
    cout << combination(n, m);
    

	return 0;
}