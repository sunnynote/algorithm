/**
 * 21-10-06
 * BOJ 16927 배열 돌리기 2
 * 구현, dfs
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R;
int arr[301][301];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int sx, int sy, int x, int y, int d, int val){
    if(x==sx && y==sy && d!=0) return; // 한바퀴 회전

    int nx = x + dx[d];
    int ny = y + dy[d];

    if(!(sx<=nx && nx<N-sx && sy<=ny && ny<M-sy)){ // map out
        nx -= dx[d];
        ny -= dy[d];

        int tmp_d = d + 1;
        nx += dx[tmp_d];
        ny += dy[tmp_d];

        int tmp = arr[nx][ny];
        arr[nx][ny] = val;

        dfs(sx, sy, nx, ny, tmp_d, tmp);
    }
    else{
        int tmp = arr[nx][ny];
        arr[nx][ny] = val;

        dfs(sx, sy, nx, ny, d, tmp);
    }
}

void solve(){
    int n = N;
    int m = M;

    int nn = N-2;
    int mm = M-2;

        for(int i=0; i<=(min(N,M)/2)-1; i++){
            int calc = (n*m) - (nn*mm);
            int rot = R%calc;

            for(int j=1; j<=rot; j++)
                dfs(i, i, i, i, 0, arr[i][i]);

            n-=2; m-=2; nn-=2; mm-=2;
        }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << arr[i][j] <<' ';
        } cout << '\n';
    }
}

void input(){
    cin >> N >> M >> R;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}