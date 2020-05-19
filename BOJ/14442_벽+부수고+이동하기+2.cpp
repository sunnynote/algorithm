/**
 * 200519
 * BOJ 14442 벽 부수고 이동하기 2
 * BFS
 */


#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int map[1005][1005];
int check[1005][1005][11];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int cnt=0;

int bfs(int x, int y){
    queue <pair<pair<int,int>,int> > q;
    q.push(make_pair( make_pair(x,y), 0));
    check[x][y][0]=1;

    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second;
        q.pop();

        if(x==N-1 && y==M-1) return check[N-1][M-1][cnt];

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(check[nx][ny][cnt]==0){

                    // 벽을 부수지 않는다
                    if(map[nx][ny]==0){
                        q.push(make_pair(make_pair(nx,ny), cnt));
                        check[nx][ny][cnt] = check[x][y][cnt] + 1;
                    }

                    // 벽을 부순다
                    else if(map[nx][ny]==1 && cnt<K){
                        q.push( make_pair(make_pair(nx,ny), cnt+1));
                        check[nx][ny][cnt+1] = check[x][y][cnt] + 1;
                    }
                }
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j] = s[j]-'0';
        }
    }

    cout << bfs(0,0);
    return 0;
}