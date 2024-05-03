#include <string>
#include <vector>

using namespace std;
long long arr[5001];

int solution(int n) {
    int answer = 0;
    arr[1] = 0;
    arr[2] = 3;
    arr[3] = 0;
    arr[4] = 11;
    if(n % 2 == 1){
        return 0;
    }
    for(int i = 6; i <= n; i += 2){
        arr[i] = (4 * arr[i-2] - arr[i-4]) % 1000000007;
        if(arr[i] < 0){
            arr[i] += 1000000007;
        }
    }
    answer = arr[n];
    return answer;
}