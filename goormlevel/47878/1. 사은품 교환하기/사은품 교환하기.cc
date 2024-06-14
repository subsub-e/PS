#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int n; cin >> n;
	while(n--){
		long long x1, x2; cin >> x1 >> x2;
		long long temp = (x1 + x2) / 12;
		long long temp1 = x1 / 5;
		cout << min(temp, temp1) << '\n';
	}
	return 0;
}