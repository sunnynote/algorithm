/**
 * BOJ 1103 게임
 * DFS + DP
 * 같은 경로에서 중복 방문 지점이 나타나면 바로 종료
 * 
 * */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int map[53][53];
int d[53][53]; // [x][y]도착시 최대 움직인 횟수
bool check[53][53];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int ans = -1;

int dfs(int x, int y){

    if( !(0<=x && x<N && 0<=y && y<M) || map[x][y]==0 ) return 0;
    if(check[x][y]){ // cycle 형성 --  종료
        cout << -1;
        exit(0);
    }


    int& ret = d[x][y];
    if(ret!=-1) return ret;

    check[x][y]=true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i] * map[x][y];
        int ny = y + dy[i] * map[x][y];
            
        d[x][y] = max(d[x][y], dfs(nx,ny)+1);
    }
    check[x][y]=false;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j]=s[j]-'0';
            if(s[j]=='H') map[i][j]=0;
        }
    }

    memset(d, -1, sizeof(d));
    cout << dfs(0,0);
    return 0;
}