/**
 * 200610
 * 2151 거울 설치
 * BFS
 * */

#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int N;
char map[52][52];
int check[52][52][4];
int sx=-1, sy=-1, ex, ey;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int ans = 987654321;

struct info{
    int x, y, dir, cnt;
};

void bfs(){
    queue <info> q;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<4; k++)
                check[i][j][k] = INF;

    for(int k=0; k<4; k++){
        q.push({sx,sy,k,0});
        check[sx][sy][k] = 0;
    }

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int cnt = q.front().cnt;
        q.pop();

        if(x==ex && y==ey) {
            if(ans > cnt) ans = cnt;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(0<=nx && nx<N && 0<=ny && ny<N){
            if(map[nx][ny]=='*') continue;

             // 거울 X
            if(check[nx][ny][dir] > cnt){
                q.push({nx,ny,dir,cnt});
                check[nx][ny][dir] = cnt;
            }

            if(map[nx][ny]=='!'){
                // 거울 O -- case1
                int nd = (dir+1)%4;
                if(check[nx][ny][nd] > cnt+1){
                    q.push({nx,ny,nd,cnt+1});
                    check[nx][ny][nd] = cnt+1;
                }

                // 거울 O -- case2
                nd = (dir+3)%4;
                if(check[nx][ny][nd] > cnt+1){
                    q.push({nx,ny,nd,cnt+1});
                    check[nx][ny][nd] = cnt+1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<N; j++){
            map[i][j] = s[j];
            if(map[i][j]=='#'){
                map[i][j]='.';
                if(sx==-1 && sy==-1){
                    sx = i;
                    sy = j;
                }
                else {
                    ex = i;
                    ey = j;
                }
            }
        }
    }

    bfs();
    cout << ans << '\n';
    
    return 0;
}
