/**
 * 21-09-13
 * BOJ 2636 치즈
 * BFS
 * */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[101][101];
int expected_melt[101][101];
bool chk[101][101];

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void bfs(int x, int y){
    queue <pair<int,int> > q;
    q.push({x, y});
    chk[x][y] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M){

                if(map[nx][ny]==0 && !chk[nx][ny]){
                    q.push({nx, ny});
                    chk[nx][ny] = true;
                }

                if(map[nx][ny]==1) expected_melt[nx][ny] = 1;
            }
        }
    }
}

int cheese_melt(int cnt){
    
    // 0인 지점에서 bfs 모두 돌림
    memset(chk, false, sizeof(chk));
    memset(expected_melt, 0, sizeof(expected_melt));

    bfs(0, 0);

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << expected_melt[i][j] <<' ' ;
    //     } cout <<'\n' ;
    // }cout <<"=========\n";

    cnt = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(expected_melt[i][j]==1) {
                map[i][j] = 0;
                cnt++;
            }
        }

    return cnt; 
    // 치즈 갯수 리턴
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> map[i][j];

    int cnt = -1;
    int cnt_res;
    int cheese_time = 0;

    while(1){
        if(cnt==0) break;

        cheese_time++;
        cnt_res = cnt;
        cnt = cheese_melt(cnt);
    }

    cout << cheese_time - 1 << ' ' << cnt_res;

    return 0;
}