/**
 * BOJ 17142
 * 17142 연구소3
 * DFS + BFS
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 987654321
using namespace std;

int N, M;
int map[52][52];
int dist[52][52];

struct Info{
    int x, y;
};
vector <Info> loc;
vector <Info> virus;
bool check[52*52];

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

int ans = MAX;

int spreadVirus(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            dist[i][j] = -1;
        
    queue <Info> q;
    for(int i=0; i<virus.size(); i++){
        q.push({virus[i].x, virus[i].y});
        dist[virus[i].x][virus[i].y]=0;
    }

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<N){
                if(map[nx][ny]==1) continue;

                if(dist[nx][ny]==-1){
                    q.push({nx,ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }

    int t = 0;
    bool endFlag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1 || map[i][j]==2) continue;

            if(dist[i][j]==-1){
                t = -1;
                endFlag = true;
                break;
            }
            t = max(dist[i][j], t);
        }
        if(endFlag) break;
    }
    
    return t;
}

void selectVirus(int idx, int cnt){
    if(cnt==M){
        int res = spreadVirus();
        if(res!=-1)
            ans = min(res, ans);
        return;
    }

    for(int i=idx; i<loc.size(); i++){
        if(check[i]) continue;

        check[i]=true;
        virus.push_back({loc[i].x, loc[i].y});
        selectVirus(i, cnt+1);
        check[i]=false;
        virus.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];

            if(map[i][j]==2){
                loc.push_back({i,j});
            }
        }
    }

    selectVirus(0, 0);

    if(ans==MAX) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}