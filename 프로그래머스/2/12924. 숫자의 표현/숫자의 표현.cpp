#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++){
        int temp = n - i;
        int index = i + 1;
        while(temp > 0){
            temp -= index;
            index++;
        }
        if(temp == 0){
            answer++;
        }
    }
    return answer;
}