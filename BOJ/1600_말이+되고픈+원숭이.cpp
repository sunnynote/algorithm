/**
 * 200605
 * BOJ 1600 말이 되고픈 원숭이
 * BFS
 * */

#include <iostream>
#include <queue>
using namespace std;

int K, W, H;
int map[205][205];
int check[205][205][35];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int hx[8]={-2,-2,-1,-1,1,1,2,2};
int hy[8]={-1,1,-2,2,-2,2,-1,1};

struct info{
    int x, y, cnt;
};

int ans = 987654321;

void solve(){
    queue <info> q;
    q.push({1,1,0});
    check[1][1][0]=0;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if(x==H && y==W){
            if(ans>check[x][y][cnt]) ans = check[x][y][cnt];
        }

        if(cnt<K){
            for(int i=0; i<8; i++){
                int nx = x + hx[i];
                int ny = y + hy[i];
                if(0<nx && nx<=H && 0<ny && ny<=W){
                    if(map[nx][ny]==0 && check[nx][ny][cnt+1]==0){
                        check[nx][ny][cnt+1] = check[x][y][cnt]+1;
                        q.push({nx,ny,cnt+1});
                    }
                }
            }
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<nx && nx<=H && 0<ny && ny<=W){
                if(map[nx][ny]==0 && check[nx][ny][cnt]==0){
                    check[nx][ny][cnt] = check[x][y][cnt]+1;
                    q.push({nx,ny,cnt});
                }
            }
        }
    }

    if(ans==987654321) ans = -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> K >> W >> H;
    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
            cin >> map[i][j];

    solve();
    cout << ans << '\n';

    return 0;
}
