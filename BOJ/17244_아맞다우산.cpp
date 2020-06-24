/**
 * 200624
 * BOJ 17244 아맞다우산
 * BFS + 조합
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
char map[52][52];
int check[52][52];
int dist[7][7]; // 물건 사이의 거리

int sx, sy, ex, ey;

struct Info{
    int x, y;
};
vector <Info> v; // 방문해야 할 점

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int bfs(int x, int y, int endX, int endY){
    memset(check, -1, sizeof(check));
    queue <Info> q;

    q.push({x,y});
    check[x][y] = 0;
    
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        q.pop();

        if(x==endX && y==endY){
            return check[x][y];
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
    
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];

            if(map[i][j]=='S'){
                map[i][j]='.';
                sx = i; sy = j;
            }
            if(map[i][j]=='E'){
                map[i][j]='.';
                ex = i; ey = j;
            }
            if(map[i][j]=='X'){
                map[i][j]='.';
                v.push_back({i,j});
            }
        }
    }

    v.push_back({ex, ey});

    // 물건 사이의 거리를 구한다.
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            dist[i][j] = bfs(v[i].x, v[i].y, v[j].x, v[j].y);
            dist[j][i] = dist[i][j];
        }
    }

    // 순서를 정한다.
    vector <int> order;
    for(int i=0; i<v.size(); i++)
        order.push_back(i);
    
    int ans = 987654321;
    
    do{
        // start~0번
        int res = bfs(sx, sy, v[order[0]].x, v[order[0]].y);      
        // 0번~end번
        for(int i=0; i<v.size()-1; i++)
            res += dist[order[i]][order[i+1]];

        ans = min(ans, res);
    }while(next_permutation(order.begin(), order.end()-1));

    cout << ans << '\n';

    return 0;
}