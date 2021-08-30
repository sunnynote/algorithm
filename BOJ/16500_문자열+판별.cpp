/***
 * 21-04-23
 * BOJ 16500 문자열 판별
 * DP 완전탐색
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int N;
string word[102];
int d[102];

bool calc(int cur, int wordNum){
    if(s.length() < cur + word[wordNum].length()) return false;

    for(int i=0; i<word[wordNum].length(); i++)
        if(s[cur+i] != word[wordNum][i]) return false;

    return true;
}

int solve(int idx){
    int &ret = d[idx];
    if(ret != -1) return ret;

    if(idx == s.length()) return ret = 1;

    ret = 0;
    for(int i=0; i<N; i++){
        if(!calc(idx, i)) continue;
        ret = max(ret, solve(idx + word[i].length()));
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> word[i];

    memset(d, -1, sizeof(d));
    cout << solve(0);

    return 0;
}