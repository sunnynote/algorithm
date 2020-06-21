/**
 * 200620
 * BOJ 1726 로봇
 * BFS
 * */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
bool map[105][105];
bool check[105][105][5];
int ans = 0;

int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};

int sx, sy, sd;
int ex, ey, ed;

struct Info{
    int x, y, d, cnt;
};

int leftChange(int x){
    if(x==1) return 4;
    if(x==4) return 2;
    if(x==2) return 3;
    return 1;
}
int rightChange(int x){
    if(x==1) return 3;
    if(x==3) return 2;
    if(x==2) return 4;
    return 1;
}

int doubleChange(int x){
    if(x==1) return 2;
    if(x==2) return 1;
    if(x==3) return 4;
    return 3;
}

void bfs(int x, int y, int d){
    queue <Info> q;
    check[x][y][d] = true;
    q.push({x,y,d,0});    

    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        int cnt = q.front().cnt;
        q.pop();

        if(x==ex && y==ey && d==ed){
            ans = cnt;
            return;
        }

        // cmd1
        for(int i=1; i<=3; i++){
            int nx = x + dx[d]*i;
            int ny = y + dy[d]*i;

            if(0<nx && nx<=N && 0<ny && ny<=M){
                if(check[nx][ny][d]) continue;

                if(!map[nx][ny]) {
                    q.push({nx, ny, d, cnt+1});
                    check[nx][ny][d]=true;
                }
                else break;
            }
        }

        // cmd2
        int nd = leftChange(d);
        if(!check[x][y][nd]){
            q.push({x,y, nd, cnt+1});
            check[x][y][nd]=true;
        }
        
        nd = rightChange(d);
        if(!check[x][y][nd]){
            q.push({x,y, nd, cnt+1});
            check[x][y][nd]=true;
        }
        nd = doubleChange(d);
        if(!check[x][y][nd]){
            q.push({x,y, nd, cnt+2});
            check[x][y][nd]=true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin >> map[i][j];

    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;
    bfs(sx, sy, sd);
    
    cout << ans << '\n';
    
    return 0;
}