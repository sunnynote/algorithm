/**
 * 200603
 * BOJ 2169 로봇 조종하기
 * DP
 * */

#include <iostream>
#include <algorithm>
#define LEFT 0
#define RIGHT 1
using namespace std;

int N, M;
int map[1005][1005];
int d[1005][1005];
int tmp[2][1005];

void solve(){
    // first line
    d[1][1]=map[1][1];
    for(int j=2; j<=M; j++)
        d[1][j] = d[1][j-1] + map[1][j];

    for(int i=2; i<=N; i++){
        //left
        tmp[LEFT][0] = d[i-1][1];
        for(int j=1; j<=M; j++)
            tmp[LEFT][j] = max(tmp[LEFT][j-1], d[i-1][j]) + map[i][j];

        //right
        tmp[RIGHT][M+1] = d[i-1][M];
        for(int j=M; j>=1; j--)
            tmp[RIGHT][j] =max(tmp[RIGHT][j+1], d[i-1][j]) + map[i][j];
        
        for(int j=1; j<=M; j++)
            d[i][j] = max(tmp[LEFT][j], tmp[RIGHT][j]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin >> map[i][j];

    solve();
    cout << d[N][M];
    return 0;
}
