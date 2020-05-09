#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int G, R;
int map[52][52];
int check[12];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

vector <pair<int,int> > avail; // 배양액 가능 한 곳
int ans = -1;
int ground = 0; // 양분 가능한 땅의 갯수

void func(){
    int cnt = 0;

    // make_map
    pair<int,int> new_map[52][52];
    memset(new_map, 0, sizeof(new_map));

    queue <pair<int,int> > q;
    for(int i=0; i<avail.size(); i++){
        if(check[i]!=0){
            int a = avail[i].first;
            int b = avail[i].second;
            new_map[a][b] = {0, check[i]};
            q.push({a, b});
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int curTime = new_map[x][y].first;
        int curColor = new_map[x][y].second;

        if(new_map[x][y].second==3) continue;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(map[nx][ny]==0) continue;

                if(new_map[nx][ny].second == 0){ // empty
                    new_map[nx][ny] = {curTime+1, curColor};
                    q.push({nx,ny});
                }
                else if(new_map[nx][ny].second == 1){ // green
                    if(curColor==2 && new_map[nx][ny].first == curTime+1){
                        cnt++;
                        new_map[nx][ny].second = 3;
                    }
                }
                else if(new_map[nx][ny].second == 2){ // red
                    if(curColor==1 && new_map[nx][ny].first == curTime+1){
                        cnt++;
                        new_map[nx][ny].second = 3;
                    }
                }
            }
        }
    }
    ans = max(ans, cnt);
}

void dfs2(int idx, int cnt){
    if(cnt==R){
        func();
        return;
    }

    for(int i=idx; i<avail.size(); i++){
        if(check[i]==0){
            check[i]=2;
            dfs2(i+1, cnt+1);
            check[i]=0;
        }
    }
}

void dfs1(int idx, int cnt){
    if(cnt==G){
        dfs2(0,0);
        return;
    }
    for(int i=idx; i<avail.size(); i++){
        if(check[i]==0){
            check[i]=1;
            dfs1(i+1, cnt+1);
            check[i]=0;
        }
    }
}

void solution(){
    dfs1(0,0);
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> G >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j]==2) avail.push_back({i,j});
            //if(map[i][j]!=0) ground++;
        }
    }
    //cout << ground << '\n';
    
    solution();

    return 0;
}