#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for(int i = 0; i < record.size(); i++){
        string x, y, z;
        stringstream ss(record[i]);
        ss >> x >> y >> z;
        if(x == "Leave"){
            continue;
        }
        m[y] = z;
    }
    
    for(int i = 0; i < record.size(); i++){
        string x, y, z;
        stringstream ss(record[i]);
        ss >> x >> y >> z;
        if(x == "Enter"){
            answer.push_back(m[y] + "님이 들어왔습니다.");
        }
        else if(x == "Leave"){
            answer.push_back(m[y] + "님이 나갔습니다.");
        }
    }
    return answer;
}