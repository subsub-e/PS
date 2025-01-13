#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1002][1002];
string stra, strb;


int main(){
    cin >> stra >> strb;
    string str1, str2;
    if(stra.length() <= strb.length()){
        str1 = stra;
        str2 = strb;
    }
    else{
        str1 = strb;
        str2 = stra;
    }

    for(int i = 1; i <= str1.length(); i++){
        for(int j = 1; j <= str2.length(); j++){
            // if(i > j){
            //     arr[i][j] = arr[i-1][j];
            //     continue;
            // }
            if(str1[i - 1] == str2[j - 1]){
                arr[i][j] = max(arr[i][j-1], arr[i-1][j-1] + 1);
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    string answer = "";
    int i = str1.length();
    int j = str2.length();

    while(i > 0 && j > 0){
        if(arr[i][j] == arr[i-1][j]){
            i--;
        }
        else if(arr[i][j] == arr[i][j-1]){
            j--;
        }
        else{
            answer += str1[i-1];
            i--;
            j--;
        }
    }
    cout << answer.length() << '\n';

    for(int i = answer.length() - 1; i >= 0; i--){
        cout << answer[i];
    }
}