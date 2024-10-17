#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    string temp1 = to_string(a);
    string temp2 = to_string(b);
    // if(stoi(temp1 + temp2) > stoi(temp2 + temp1))
    return stoi(temp1 + temp2) > stoi(temp2 + temp1);
}

string solution(vector<int> numbers) {
    string answer = "";
    stable_sort(numbers.begin(), numbers.end(), comp);
    if(numbers[0] == 0){
        return "0";
    }
    for(int i = 0; i < numbers.size(); i++){
        answer += to_string(numbers[i]);
    }
    return answer;
}