#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

char map[7][7];
bool check[7][7]; // bfs
bool go_check[7][7]; // 꼭 방문해야하는 곳
bool sel[26];

int ans=0;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool calc(){
    int is4=0;
    
    for(int i=0; i<25; i++)
        if(sel[i]){
            int x = i/5;
            int y = i%5;
            if(map[x][y]=='S') is4++;
        }

    if(is4>=4) return true;
    else return false;
}

bool bfs(){
    // init
    memset(go_check, 0, sizeof(go_check));
    memset(check,0, sizeof(check));

    bool flag=false;
    int stX=0, stY=0;

    for(int i=0; i<25; i++){
        if(sel[i]){
            int x = i/5;
            int y = i%5;

            // 시작점 잡기
            if(!flag){
                stX=x; stY=y; 
                flag=true;
            }

            // 갈 곳 표시
            go_check[x][y]=true;
        }
    }
    
    queue <pair<int,int> > q;
    q.push(make_pair(stX, stY));
    check[stX][stY]=true;

    int cnt=1;
    bool flag7=false;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(cnt==7){
            flag7=true;
            break;
        }

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0<=nx && nx<5 && 0<=ny && ny<5){
                if(go_check[nx][ny] && !check[nx][ny]){
                    q.push(make_pair(nx,ny));
                    check[nx][ny]=true;
                    cnt++;
                }
            }
        }
    }
    
    if(flag7) return true;
    else return false;
}

void dfs(int idx, int cnt){
    if(cnt==7){
        if(calc() && bfs()) ans++;
        return;
    }

    for(int i=idx; i<25; i++){
        if(sel[i]) continue;

        sel[i]=true;
        dfs(i, cnt+1);
        sel[i]=false;
    }
}

int main(){
    for(int i=0; i<5; i++){
        string s;
        cin >> s;
        for(int j=0; j<5; j++){
            map[i][j] = s[j];
        }
    }

    // 7명 뽑는다
    dfs(0, 0);

    cout << ans;
    return 0;
}