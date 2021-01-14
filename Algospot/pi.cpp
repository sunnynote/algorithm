/**
 * 21-01-14
 * 동적계획법
 * */

#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

string S;
int cache[10005];

int level(int a, int b){
    string s = S.substr(a, b-a+1);

    if(s == string(s.size(), s[0]))
        return 1;

    bool progressive = true;
    for(int i=0; i<s.size()-1; i++){
        if(s[i+1]-s[i] != s[1]-s[0])
            progressive = false;
    }

    if(progressive && abs(s[1]-s[0])==1)
        return 2;

    bool alter = true;
    for(int i=0; i<s.size(); i++){
        if(s[i] != s[i%2]) 
            alter = false;
    }
    if(alter) return 4;
    if(progressive) return 5;
    return 10;
}

int solve(int loc){
    if(loc==S.size()) return 0;

    int &ret = cache[loc];
    if(ret!=-1) return ret;

    ret = INF;
    for(int i=3; i<=5; i++){
        if(loc+i <= S.size()){
            ret = min(ret, solve(loc+i) + level(loc, loc+i-1));
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        memset(cache, -1, sizeof(cache));
        cin >> S;
        int ans = solve(0);
        cout << ans << '\n';
    }

    return 0;
}