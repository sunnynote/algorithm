/**
 * 21-03-31
 * BOJ 2602 돌다리 건너기
 * DP - Top Down
 */

#include <iostream>
#include <cstring>
using namespace std;

string s;
string str[2];
int d[2][102][20]; // [x][y][현재 문자]
int ans = 0;

int solve(int x, int y, int idx){
    if(idx==s.length()) return 1;

    int &ret = d[x][y][idx];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=y; i<str[0].length(); i++)
        if(str[x][i] == s[idx])
            ret += solve(1-x, i+1, idx+1);

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for(int i=0; i<2; i++)
        cin >> str[i];

    memset(d, -1, sizeof(d));
    for(int i=0; i<2; i++)
        ans += solve(i, 0, 0);

    cout << ans << '\n';
    return 0;
}