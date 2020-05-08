#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int map[505][505];
int d[505][505];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int dfs(int x, int y){
    if(x==N && y==M) return 1;
    if(d[x][y]>-1) return d[x][y];

    d[x][y]=0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0<nx && nx<=N && 0<ny && ny<=M){
            if(map[x][y] > map[nx][ny])
                d[x][y] += dfs(nx, ny);
        }
    }

    return d[x][y];
}

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin >> map[i][j];

    memset(d, -1, sizeof(d));

    cout << dfs(1,1);
}