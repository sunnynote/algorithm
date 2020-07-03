/**
 * 200701
 * BOJ 2665 미로만들기
 * BFS
 */

#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int N;
int map[52][52];
int check[52][52];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

struct Info{
    int x, y;
};

int bfs(){
    int ans = INF;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            check[i][j] = INF;
    
    queue <Info> q;
    q.push({0,0});
    check[0][0] = 0;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<N){
                if(map[nx][ny]==1 && check[nx][ny]>check[x][y]){
                    q.push({nx,ny});
                    check[nx][ny] = check[x][y];
                }

                if(map[nx][ny]==0 && check[nx][ny]>check[x][y]+1){
                    q.push({nx,ny});
                    check[nx][ny] = check[x][y] +1;
                }
            }
        }
    }

    return check[N-1][N-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<N; j++)
            map[i][j] = s[j] - '0';
    }

    cout << bfs();
    return 0;
}