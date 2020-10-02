/**
 * 20-10-02
 * BOJ 17129 윌리암
 * BFS
 * */

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 987654321
using namespace std;

int N, M;
int map[3001][3001];
int check[3001][3001];
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
int startX, startY;

void solve(int x, int y){
    memset(check, -1, sizeof(check));
    queue <pair<int,int> > q;
    q.push({x,y});
    check[x][y] = 0;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(map[nx][ny]==1 || check[nx][ny]!=-1) continue;
                
                q.push(make_pair(nx,ny));
                check[nx][ny] = check[x][y]+1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j] = s[j]-'0';
            if(map[i][j]==2){
                startX = i; startY = j;
                map[i][j] = 0;
            }
        }
    }

    solve(startX, startY);

    int res = MAX;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]!=0 && map[i][j]!=1 && check[i][j]!=-1)
                if(res > check[i][j])
                    res = check[i][j];
        }
    }

    if(res==MAX) cout << "NIE" << '\n';
    else cout << "TAK" << '\n' << res << '\n';
    return 0;
}
