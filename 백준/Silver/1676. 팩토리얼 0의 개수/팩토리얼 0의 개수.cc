#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cout << n / 5 + n / 25 + n / 125;
	return 0;
}