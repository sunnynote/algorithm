/**
 * 21-03-29
 * BOJ 17130 토끼가 정보섬에 올라온 이유
 * DP - memoization
 **/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
char map[1002][1002];
int d[1002][1002];
int stX, stY;

int dx[3] = { -1, 0, 1 };
int ans = -1;

void solve(int x, int y){
    d[x][y] = 0;

    for(int j=y+1; j<=M; j++){
        for(int i=1; i<=N; i++){
            if(map[i][j] == '#') continue;
            int cnt = -1;

            for(int k=0; k<3; k++){
                int px = i - dx[k];
                int py = j - 1;

                if(0<px && px<=N && 0<py && py<=M)
                    cnt = max(cnt, d[px][py]);
            }

            if(cnt==-1) continue;

            if(map[i][j]=='C') cnt += 1;
            if(map[i][j]=='O') ans = max(ans, cnt);
            d[i][j] = cnt;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];

            if(map[i][j] == 'R'){
                stX = i;
                stY = j;
            }
        }
    }

    memset(d, -1, sizeof(d));
    solve(stX, stY);

    cout << ans;

    return 0;
}