/**
 * 200701
 * BOJ 9376 탈옥
 * BFS + IDEA
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
char tmp[105][105];
char map[110][110];
int check[110][110];
int sum[110][110];

struct Info{
    int x, y;
};
vector <Info> person;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs(int x, int y){
    queue <Info> q;
    memset(check, -1, sizeof(check));

    q.push({x,y});
    check[x][y] = 0;

    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N+2 && 0<=ny && ny<M+2){
                if(map[nx][ny]=='*') continue;

                if(map[nx][ny]=='.'){
                    if(check[nx][ny]==-1 || check[nx][ny] > check[x][y]){
                        q.push({nx,ny});
                        check[nx][ny] = check[x][y];
                    }
                }
                    
                if(map[nx][ny]=='#'){
                    if(check[nx][ny]==-1 || check[nx][ny] > check[x][y]+1){
                        q.push({nx,ny});
                        check[nx][ny] = check[x][y] + 1;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){

        // init
        person.clear();
        
        cin >> N >> M;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> tmp[i][j];

                if(tmp[i][j]=='$'){
                    person.push_back({i,j});
                    tmp[i][j]='.';
                }
            }
        }

        // 맵 확장
        for(int i=0; i<N+2; i++){
            for(int j=0; j<M+2; j++){
                if(i==0 || i==N+1 || j==0 || j==M+1)
                    map[i][j]='.';
                else
                    map[i][j]=tmp[i-1][j-1];
            }
        }

        // (0,0)~
        bfs(0, 0);
        int dist1[110][110];
        for(int i=0; i<N+2; i++){
            for(int j=0; j<M+2; j++){
                if(map[i][j]=='*') dist1[i][j]=0;
                else dist1[i][j] = check[i][j];
            }
        }

        // person1
        bfs(person[0].x+1, person[0].y+1);
        int dist2[110][110];
        for(int i=0; i<N+2; i++){
            for(int j=0; j<M+2; j++){
                if(map[i][j]=='*') dist2[i][j]=0;
                else dist2[i][j] = check[i][j];
            }
        }

        // person2
        bfs(person[1].x+1, person[1].y+1);
        int dist3[110][110];
        for(int i=0; i<N+2; i++){
            for(int j=0; j<M+2; j++){
                if(map[i][j]=='*') dist3[i][j]=0;
                else dist3[i][j] = check[i][j];
            }
        }

        // sum!
        int ans = 987654321;
        for(int i=0; i<N+2; i++){
            for(int j=0; j<M+2; j++){
                if(map[i][j]=='*') continue;

                sum[i][j] = dist1[i][j] + dist2[i][j] + dist3[i][j];
            
                if(map[i][j]=='#') sum[i][j]-=2;
                if(ans > sum[i][j]) ans = sum[i][j];
            }
        }

        cout << ans << '\n';
    }
    return 0;
}