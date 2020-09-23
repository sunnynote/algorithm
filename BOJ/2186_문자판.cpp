/**
 * 200923
 * BOJ 2186
 * 문자판
 * DFS + DP
 * */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K;
char map[102][102];
int dp[102][102][82];
// dp[x][y][idx] : [x][y]에 있는 알파벳을 [idx]번째로 사용할 때
// 나올 수 있는 정답의 갯수

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

string str;

int dfs(int x, int y, int idx){
    if(idx==str.length()) return 1;

    int &ret = dp[x][y][idx];
    if(ret!=-1) return ret;
    ret = 0;
    
    for(int i=0; i<4; i++){
        for(int j=1; j<=K; j++){
            int nx = x + dx[i]*j;
            int ny = y + dy[i]*j;

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(map[nx][ny]==str[idx])
                    ret += dfs(nx,ny,idx+1);
            }
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j] = s[j];
        }
    }

    cin >> str;

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==str[0]){
                ans += dfs(i,j,1);
            }
        } 
    }
    
    cout << ans << '\n';
    return 0;
}