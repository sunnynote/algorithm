/**
 * 200922
 * BOJ 1938
 * 통나무 옮기기
 * BFS
 * */

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N;
char map[52][52];
bool check[52][52][2];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int d=-1, startX, startY;
int dd=-1, endX, endY;

struct Info{
    int x,y,d,cnt;
};

int ans = MAX;

bool chkGaro(int x, int y){
    if(map[x][y]=='0' && map[x][y-1]=='0' && map[x][y+1]=='0')
        return true;
    return false;
}

bool chkSero(int x, int y){
    if(map[x][y]=='0' && map[x-1][y]=='0' && map[x+1][y]=='0')
        return true;
    return false;
}

bool chkRange(int x, int y, int d){
    if(d==0){
        if(0<=x && x<N && 0<y && y<N-1) return true;
        return false;
    }
    else{
        if(0<x && x<N-1 && 0<=y && y<N) return true;
        return false;
    }
}

void bfs(){
    queue <Info> q;
    q.push({startX, startY, d, 0});
    check[startX][startY][d]=true;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        int cnt = q.front().cnt;
        q.pop();

        if(d==dd && x==endX && y==endY){
            ans = min(ans, cnt);
            return;
        }

        // U D L R
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(chkRange(nx,ny,d)){
                if(!check[nx][ny][d]){
                    if( (d==0 && chkGaro(nx,ny)) || (d==1 && chkSero(nx,ny))){
                        check[nx][ny][d]=true;
                        q.push({nx, ny, d, cnt+1});
                    }
                }
            }
        }

        // T
        if(chkRange(x,y,abs(d-1))){
            d = abs(d-1);
            if(!check[x][y][d]){
                if( (d==1 && chkSero(x,y) && chkSero(x,y-1) && chkSero(x,y+1))
                    || (d==0 && chkGaro(x,y) && chkGaro(x-1,y) && chkGaro(x+1,y))){
                        check[x][y][d]=true;
                        q.push({x, y, d, cnt+1});
                }
            }
        } 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<N; j++){
            map[i][j] = s[j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]=='B' && d==-1){
                if(map[i+1][j]=='B') {
                    d=1;
                    startX = i+1; startY = j;
                    map[i][j]='0';
                    map[i+1][j]='0';
                    map[i+2][j]='0';
                }
                else if(map[i][j+1]=='B') {
                    d=0;
                    startX = i; startY = j+1;
                    map[i][j]='0';
                    map[i][j+1]='0';
                    map[i][j+2]='0';
                }
            }

            if(map[i][j]=='E' && dd==-1){
                if(map[i+1][j]=='E') {
                    dd=1;
                    endX = i+1; endY = j;
                    map[i][j]='0';
                    map[i+1][j]='0';
                    map[i+2][j]='0';
                }
                else if(map[i][j+1]=='E') {
                    dd=0;
                    endX = i; endY = j+1;
                    map[i][j]='0';
                    map[i][j+1]='0';
                    map[i][j+2]='0';
                }
            }
        }
    }

    bfs();

    if(ans==MAX) cout << 0 << '\n';
    else cout << ans << '\n';
    return 0;
}