/**
 * BOJ 1743 음식물 피하기
 * BFS 
 * */

#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int map[105][105];
bool check[105][105];
int ans = -1;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void bfs(int x, int y){
    queue <pair<int,int> > q;
    q.push(make_pair(x,y));
    check[x][y]=true;
    int cnt = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(map[nx][ny]==1 && check[nx][ny]==0){
                    q.push(make_pair(nx,ny));
                    check[nx][ny]=true;
                    cnt++;
                }
            }
        }
    }

    ans = max(ans, cnt);

}
int main(){
    cin >> N >> M >> K;
    for(int k=0; k<K; k++){
        int a, b;
        cin >> a >> b;
        map[a-1][b-1]=1;
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(map[i][j]==1 && check[i][j]==0)
                bfs(i,j);
    
    cout << ans;
    return 0;
}