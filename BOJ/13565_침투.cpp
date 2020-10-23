/**
 * 20-10-06
 * BOJ 13565 침투
 * BFS
 * */

#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool map[1002][1002];
bool check[1002][1002];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void bfs(int x, int y){
    queue <pair<int,int> > q;
    q.push({x,y});
    check[x][y] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(!check[nx][ny] && !map[nx][ny]){
                    q.push({nx,ny});
                    check[nx][ny] = true;
                }
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
        for(int j=0; j<M; j++)
            map[i][j] = s[j]-'0';
    }

    for(int j=0; j<M; j++)
        if(!map[0][j]) bfs(0,j);

    bool flag=false;
    for(int j=0; j<M; j++)
        if(!map[N-1][j] && check[N-1][j]) flag=true;

    if(flag) cout << "YES" <<'\n';
    else cout << "NO" << '\n';

    return 0;
}