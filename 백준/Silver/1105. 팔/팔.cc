#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    if(a.length() != b.length()){
        cout << 0;
        return 0;
    }

    int cnt_a = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '8' && b[i] == '8'){
            cnt_a++;
        }
        else{
            if(a[i] != b[i]){
                break;
            }
            else{
                continue;
            }
        }
    }
    
    cout << cnt_a;


	return 0;
}