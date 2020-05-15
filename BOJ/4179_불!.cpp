#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
char map[1004][1004];
int check[1004][1004];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

queue <pair<int,int> > fq; // 불 번진다

int bfs(int x, int y){

    queue <pair<int,int> > q;
    q.push({x,y});
    check[x][y]=0;

    while(!q.empty()){

        int fSize = fq.size();
        for(int i=0; i<fSize; i++){
            int fx = fq.front().first;
            int fy = fq.front().second;
            fq.pop();

            for(int i=0; i<4; i++){
                int nx = fx + dx[i];
                int ny = fy + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<M){
                    if(map[nx][ny]=='.'){
                        map[nx][ny]='F';
                        fq.push({nx,ny});
                    }
                }
            }
        }

        int qSize = q.size();
        for(int i=0; i<qSize; i++){
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if(x==0 || x==N-1 || y==0 || y==M-1){
                return check[x][y]+1;
            }

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<M){
                    if(map[nx][ny]=='.' && check[nx][ny]==-1){
                        q.push({nx,ny});
                        check[nx][ny] = check[x][y] + 1;
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

    cin >> N >> M;

    int sx, sy;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j] = s[j];
            if(map[i][j]=='J'){
                sx = i; sy = j;
                map[i][j] = '.';
            }
            if(map[i][j]=='F')
                fq.push({i,j});
        }
    }

    memset(check, -1, sizeof(check));
    int ans = bfs(sx, sy);
    if(ans==-1) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';

    return 0;
}