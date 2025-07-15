#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
// Add more as needed
using namespace std;

int main() {
    string s;
    cin>>s;
    unordered_map<char,int> m;
    int n = s.length();

    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    string result = "";
    while(m.size()>0){
        pair<char,int> i = *m.begin();
        result += i.first;
        i.second--;
        if(i.second==0){
            m.erase(i.first);
        }
    }
    cout<<result;
}