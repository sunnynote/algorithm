/**
 * 200709
 * BOJ 10711 모래성
 * BFS
 * */

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1004][1004];
int adj[1004][1004];
bool check[1004][1004];

int dx[8]={0,0,1,-1, -1,-1,1,1};
int dy[8]={-1,1,0,0, -1,1,-1,1};

struct Info{
    int x, y;
};
queue <Info> q,nq;
int ans = 0;

int bfs(){

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(check[nx][ny]) continue;

                if(map[nx][ny]!=0) 
                    adj[nx][ny] += 1;
                if(adj[nx][ny] >= map[nx][ny]){
                    nq.push({nx,ny});
                    check[nx][ny]=true;
                }
            }
            
        }

        if(q.empty()){
            ans++;
            while(!nq.empty()){
                q.push(nq.front());
                nq.pop();
            }
        }
    }

    return ans-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            if(s[j]=='.') {
                map[i][j] = 0;
                check[i][j] = true;
                q.push({i,j});
            }
            else map[i][j] = s[j] - '0';
        }
    }

    cout << bfs();
    return 0;
}
