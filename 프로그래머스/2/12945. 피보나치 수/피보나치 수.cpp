#include <string>
#include <vector>

using namespace std;

long long arr[100001];

int solution(int n) {
    int answer = 0;
    
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-1] % 1234567 + arr[i-2] % 1234567) % 1234567;
    }
    
    answer = arr[n];
    
    return answer;
}