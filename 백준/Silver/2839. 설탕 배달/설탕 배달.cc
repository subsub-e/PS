#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


int arr[5001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	

	int n; cin >> n;
	
	int end = n / 5 + 1;

	while(end--){
		int temp = n - (end * 5);
		//cout << temp << '\n';
		if(temp % 3 == 0){
			cout << end + temp / 3;
			return 0;
		}
	}
	cout << -1;
	return 0;
}