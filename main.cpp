#include <iostream>
#include "string"
#include "map"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    string CUR, NEW;
    char CHAR;
    map<string, map<char, string>> ss;
    cin >> CUR;
    while(CUR != "END"){
        cin >> CHAR >> NEW;
        map<char, string> a = ss[CUR];
        a.emplace(CHAR, NEW);
        ss[CUR] = a;
        cin >> CUR;
    }
    vector<string> end;
    cin >> CUR;
    while (CUR != "END"){
        end.push_back(CUR);
        cin >> CUR;
    }
    string start;
    cin >> start;
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        map<char, string> a = ss[start];
        if(i == s.size() - 1 && find(end.begin(), end.end(), start) - end.end() != end.size()) {
            cout << 1 << endl;
            cout << i + 1 << endl;
            cout << start << endl;
            break;
        }
        auto f = a.find(s[i]);
        if(f == a.end()){
            cout << 0 << endl;
            cout << i << endl;
            cout << start << endl;
            break;
        }
        start = f->second;
    }
    return 0;
}
