#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool comp(string str1, string str2){
    if(str1.length() == str2.length()){
        return str1 < str2;
    }
    else{
        return str1.length() < str2.length();
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    vector<string> v;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < n - 1; i++){
        if(v[i] == v[i + 1]){
            continue;
        }
        cout << v[i] << '\n';
    }
    cout << v[v.size() - 1];
	return 0;
}