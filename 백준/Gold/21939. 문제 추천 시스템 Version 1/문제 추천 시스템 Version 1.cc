#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    map<int, int> m;
    set<pair<int, int> > s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int p, l;
        cin >> p >> l;
        m[p] = l;
        s.insert(make_pair(l, p));
    }
    int mn; cin >> mn;
    //m.erase(1);
    for(int i = 0; i < mn; i++){
        string str; 
        int a;
        cin >> str >> a;
        if(str == "add"){
            int b; cin >> b;
            m[a] = b;
             s.insert(make_pair(b, a));
        }
        else if(str == "recommend"){
            if(a == 1){
                auto it = prev(s.end());
                cout << it->second << '\n';
            }
            else{
                auto it = s.begin();
                cout << it->second << '\n';
            }
        }
        else if(str == "solved"){
            int hard = m[a];
            s.erase(make_pair(hard, a));
            m.erase(a);
        }
    }
}