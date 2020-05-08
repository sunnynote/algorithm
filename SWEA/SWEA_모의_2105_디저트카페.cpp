/**
 * SWEA 2105 디저트카페
 * DFS + BACKTRACKING
 * 한 방향으로 가는 것을 고려해야 함!
 * 시작점 도착시, 방문 되어 있는 것도 확인.
 * */

#include <iostream>
#include <cstring>
using namespace std;

int ans;
int N;
int map[22][22];
bool check[101];

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,-1,1};
int sx, sy;

void dfs(int x, int y, int cnt, int d){
    if(x==sx && y==sy && d==3){
        ans = max(ans, cnt);
        return;
    }

    for(int i=0; i<2; i++){
        int nx, ny, nd;

        // 방향 전환 여부
        if(i==0){
            nd = d;
            nx = x + dx[nd];
            ny = y + dy[nd];
        }
        else{
            if(x==sx && y==sy) continue;
            if(d==3) continue;

            nd = d+1;
            nx = x + dx[nd];
            ny = y + dy[nd];
        }

        // 시작점이면 탈출(방문되어 있기 때문에)
        if(nx==sx && ny==sy){
            dfs(nx,ny,cnt+1, nd);
            break;
        }

        if(!(0<=nx && nx<N && 0<=ny && ny<N)) continue;
        if(check[map[nx][ny]]) continue;
        
        check[map[nx][ny]] = true;
        dfs(nx, ny, cnt+1, nd);
        check[map[nx][ny]] = false;
    }
}

int main(int argc, char** argv){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        cin >> N;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> map[i][j];

        ans = -1;
        memset(check,0,sizeof(check));

        for(int i=0; i<N; i++){
            for(int j=1; j<N-1; j++){
                sx = i; sy = j;

                check[map[i][j]] = true;
                dfs(i, j, 0, 0);
                check[map[i][j]] = false;
            }
        }

        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}
