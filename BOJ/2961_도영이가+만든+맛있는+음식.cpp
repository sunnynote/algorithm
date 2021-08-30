/**
 * 21-04-23
 * BOJ 2961 도영이가 만든 맛있는 음식
 * 조합
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int info[10][2];
int chk[10];
int ans = 987654321;

void solve(int cnt, int idx, int num){
    if(num==cnt){
        int resS = 1, resB = 0;

        for(int i=0; i<N; i++)
            if(chk[i]){
                resS *= info[i][0];
                resB += info[i][1];
            }

        ans = min(abs(resS-resB), ans);
        return;
    }

    for(int i=idx; i<N; i++){
        if(chk[i]) continue;

        chk[i] = true;
        solve(cnt+1, i, num);
        chk[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++)
        cin >> info[i][0] >> info[i][1];

    for(int i=1; i<=N; i++){
        memset(chk, 0, sizeof(chk));
        solve(0, 0, i);
    }

    cout << ans;

    return 0;
}