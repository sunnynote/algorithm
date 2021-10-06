/**
 * 21-10-05
 * BOJ 2638 치즈
 * BFS
 * */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
bool map[101][101];
bool chk[101][101];
int out_cnt[101][101];
int ans = 0;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int count_cheese(){
    int cnt = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(map[i][j]==1) cnt++;

    return cnt;
}

void bfs(){    
    memset(chk, 0, sizeof(chk));
    memset(out_cnt, 0, sizeof(out_cnt));

    queue <pair<int,int> > q;
    q.push({0, 0});
    chk[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(chk[nx][ny]) continue;

                if(map[nx][ny]) 
                    out_cnt[nx][ny]++;
                if(!map[nx][ny]){
                    q.push({nx, ny});
                    chk[nx][ny] = 1;
                }
            }
        }
    }
}

void melt_cheese(){
    bfs();

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(out_cnt[i][j]>=2) map[i][j] = 0;
}

void solve(){
    while(1){
        if(count_cheese()==0) break;

        melt_cheese();
        ans++;
    }

    cout << ans << '\n';
}

void input(){
    cin >> N >> M;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> map[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}