/**
 * 21-03-28
 * BOJ 17836 공주님을 구해라!
 * BFS
 * */

#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, T;
int map[102][102];
int chk[102][102][2];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Info{
    int x, y;
    bool sword;
    Info(){};
    Info(int _x, int _y, int _sword){
        x = _x; y = _y; sword = _sword;
    }
};

void solve(){
    queue <Info> q;
    q.push(Info(1,1,0));
    chk[1][1][0] = 0;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        bool sword = q.front().sword;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<nx && nx<=N && 0<ny && ny<=M){
                if(sword && chk[nx][ny][1] > chk[x][y][1] + 1){
                    q.push(Info(nx, ny, sword));
                    chk[nx][ny][sword] = chk[x][y][sword] + 1;
                }
                else if(map[nx][ny]==0 && chk[nx][ny][0] > chk[x][y][0] + 1){
                    q.push(Info(nx, ny, sword));
                    chk[nx][ny][0] = chk[x][y][0] + 1;
                }
                else if(map[nx][ny]==2 && chk[nx][ny][1] > chk[x][y][0] + 1){
                    q.push(Info(nx, ny, true));
                    chk[nx][ny][1] = chk[x][y][0] + 1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> T;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
            chk[i][j][0] = INF;
            chk[i][j][1] = INF;
        }

    solve();

    int ans = min(chk[N][M][0], chk[N][M][1]);

    if(ans<=T) cout << ans;
    else cout << "Fail";

    return 0;
}