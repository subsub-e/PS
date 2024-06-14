#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	string str; cin >> str;
	set<string> s;
	vector<tuple<string, string, string> > v;
	for(int i = 1; i < n-1; i++){
		for(int j = 1; j < n- i; j++){
			string str1 = str.substr(0, i);
			string str2 = str.substr(i, j);
			string str3 = str.substr(i + j);
			//cout << str1 << ' ' << str2 << ' ' << str3 << '\n';
			v.push_back(make_tuple(str1, str2, str3));
			s.insert(str1);
			s.insert(str2);
			s.insert(str3);
		}
	}
	int maxans = 0;
	for(int i = 0; i < (int) v.size(); i++){
		string str1, str2, str3;
		tie(str1, str2, str3) = v[i];
		int sum = 0;
		int cnt = 1;
		for(auto it : s){
			if(it == str1){
				break;
			}
			cnt++;
		}
		sum += cnt;
		cnt = 1;
		for(auto it : s){
			if(it == str2){
				break;
			}
			cnt++;
		}
		sum += cnt;
		cnt = 1;
		for(auto it : s){
			if(it == str3){
				break;
			}
			cnt++;
		}
		sum += cnt;
		maxans = max(maxans, sum);
	}
	cout << maxans;
	return 0;
}