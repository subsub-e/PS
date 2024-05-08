#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int ttt = 0;
    
    string temp_m = "";
    for(int i = 0; i < m.length(); i++){
        if(m[i] == '#' && m[i-1] == 'C'){
            temp_m.pop_back();
            temp_m.push_back('H');
        }
        else if(m[i] == '#' && m[i-1] == 'D'){
            temp_m.pop_back();
            temp_m.push_back('I');
        }
        else if(m[i] == '#' && m[i-1] == 'E'){
            temp_m.pop_back();
            temp_m.push_back('J');
        }
        else if(m[i] == '#' && m[i-1] == 'F'){
            temp_m.pop_back();
            temp_m.push_back('K');
        }
        else if(m[i] == '#' && m[i-1] == 'G'){
            temp_m.pop_back();
            temp_m.push_back('L');
        }
        else if(m[i] == '#' && m[i-1] == 'A'){
            temp_m.pop_back();
            temp_m.push_back('M');
        }
        else if(m[i] == '#' && m[i-1] == 'B'){
            temp_m.pop_back();
            temp_m.push_back('N');
        }
        else{
            temp_m.push_back(m[i]);
        }
    }
    
    for(int i = 0; i < musicinfos.size(); i++){
        int start_t = stoi(musicinfos[i].substr(0, 2));
        int start_m  = stoi(musicinfos[i].substr(3, 2));
        int end_t = stoi(musicinfos[i].substr(6, 2));
        int end_m  = stoi(musicinfos[i].substr(9, 2));
        //cout << start << ' ' << end << ' ';
        int index;
        for(int j = 12; j < musicinfos[i].length(); j++){
            if(musicinfos[i][j] == ','){
                index = j;
            }
        }
        string name = musicinfos[i].substr(12, index - 12);
        string music_m = musicinfos[i].substr(index + 1);
        string music = "";
        for(int i = 0; i < music_m.length(); i++){
            if(music_m[i] == '#' && music_m[i-1] == 'C'){
                music.pop_back();
                music.push_back('H');
            }
            else if(music_m[i] == '#' && music_m[i-1] == 'D'){
                music.pop_back();
                music.push_back('I');
            }
            else if(music_m[i] == '#' && music_m[i-1] == 'E'){
                music.pop_back();
                music.push_back('J');
            }
            else if(music_m[i] == '#' && music_m[i-1] == 'F'){
                music.pop_back();
                music.push_back('K');
            }
            else if(music_m[i] == '#' && music_m[i-1] == 'G'){
                music.pop_back();
                music.push_back('L');
            }
            else if(music_m[i] == '#' && music_m[i-1] == 'A'){
                music.pop_back();
                music.push_back('M');
            }
            else if(music_m[i] == '#' && music_m[i-1] == 'B'){
                music.pop_back();
                music.push_back('N');
            }
            else{
                music.push_back(music_m[i]);
            }
        }
        int t = (end_t - start_t) * 60 + end_m - start_m;
        
        int len = t / music.length();
        int div = t % music.length();
        string temp = "";
        for(int j = 0; j < len; j++){
            temp += music;
        }
        for(int j = 0; j < div; j++){
            temp += music[j];
        }
        
        //cout << temp << '\n';
        
        if(temp.find(temp_m) == string::npos){
            continue;
        }
        else{
            if(ttt < t){
                answer = name;
                ttt = t;
            }
        }
        
    }
    
    
    
    if(answer == ""){
        answer = "(None)";
    }
    return answer;
}