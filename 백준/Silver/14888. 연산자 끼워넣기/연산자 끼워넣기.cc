#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, arr[12], op[4], max_ans = INT_MIN, min_ans = INT_MAX;

void DFS(int x, int res) {

	if (x == n - 1) {
		max_ans = max(max_ans,res);
		min_ans = min(min_ans,res);
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;

			if (i == 0) {
				DFS(x + 1, res + arr[x + 1]);
			}
			else if (i == 1) {
				DFS(x + 1, res - arr[x + 1]);

			}
			else if (i == 2) {
				DFS(x + 1, res * arr[x + 1]);

			}
			else if (i == 3) {
				DFS(x + 1, res / arr[x + 1]);
			}
			op[i]++;
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	DFS(0, arr[0]);

	cout << max_ans << '\n';
	cout << min_ans << '\n';


	return 0;
	
}