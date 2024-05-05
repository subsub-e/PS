#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    int temp = __gcd(arr[0], arr[1]);
    int gcddd = (arr[0] / temp) * (arr[1] / temp) * temp;
    for(int i = 2; i < arr.size(); i++){
        int temp1 = __gcd(gcddd, arr[i]);
        gcddd = (gcddd / temp1) * (arr[i] / temp1) * temp1;
    }
    return gcddd;
}