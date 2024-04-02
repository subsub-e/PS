#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int n, m;
int arr[100001];
int cnt;

int find(int x){
	if(arr[x] == x){
		return x;
	}
	return arr[x] = find(arr[x]);
}

void Union(int a, int b){
	int pos_a = find(a);
	int pos_b = find(b);
	if(pos_a != pos_b){
		arr[pos_a] = pos_b;
	}
	else{
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

	for(int i = 1; i <= n ; i++){
		arr[i] = i;
 	}

	for(int i = 0; i < m; i++){
		int x1, x2;
		cin >> x1 >> x2;
		Union(x1, x2);
	}

	for(int i = 2; i <= n; i++){
		if(find(i) != find(i - 1)){
			Union(i, i-1);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}