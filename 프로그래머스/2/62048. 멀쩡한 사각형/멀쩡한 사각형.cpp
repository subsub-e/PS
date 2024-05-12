#include <algorithm>
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long temp1 = max((long long) w,(long long) h);
    long long temp2 = min((long long)w,(long long) h);
    long long g = __gcd((long long)w,(long long) h);
    
    long long ww = w / g;
    long long hh = h / g;
    
    long long cut = ((ww * hh) - (ww - 1) * (hh - 1));
    answer = (long long)w * (long long)h - cut * g;
    return answer;
}
