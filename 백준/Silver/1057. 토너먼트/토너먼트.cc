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

    int n, a, b;
	cin >> n >> a >> b;
	int cnt = 0;
	while(a != b){
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}
	
	if(cnt == 0){
		cout << -1;
	}
	else{
		cout << cnt;
	}
	return 0;
}