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

    int n; cin >> n;
	vector<int> v;
	vector<int> ans;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.push_back(x);
		ans.push_back(x);
	}

	sort(ans.rbegin(), ans.rend());

	int m; cin >> m;

	int index = 0;
	while(m > 0){
		int flag = 0;
		for(int i = 0; i < v.size(); i++){
			if(v[i] != ans[i]){
				flag = 1;
			}
		}
		if(flag == 0){
			break;
		}
		for(int i = 0; i < v.size() -1; i++){
			int maxans = max_element(v.begin() + index, v.end() - i) - v.begin();
			//cout << maxans << '\n';
			if(maxans - index <= m){
				int temp = v[maxans];
				for(int j = maxans; j > index; j--){
					v[j] = v[j - 1];
				}
				v[index] = temp;
				m -= (maxans - index);
				index++;
				break;
			}
		}

	}

	for(int i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
	return 0;
}