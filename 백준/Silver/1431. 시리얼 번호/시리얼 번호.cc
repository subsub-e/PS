#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <map>
#include <climits>
#include <set>
using namespace std;

bool compare(string a, string b){
    int x = a.length();
    int y = b.length();
    int xsum = 0;
    int ysum = 0;

    if(x != y){
        return x < y;
    }

    for(int i = 0; i < x; i++){
        if(a[i] >= '0' && a[i] <= '9'){
            xsum += (int) a[i] - 48;
        }
    }

    for(int i = 0; i < y; i++){
        if(b[i] >= '0' && b[i] <= '9'){
            ysum += (int) b[i] - 48;
        }
    }

    if(xsum != ysum){
        return xsum < ysum;
    }

    return a < b;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    string arr[51];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, compare);

    for(int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }
    
    
    return 0;
}