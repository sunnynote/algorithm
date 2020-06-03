/**
 * 200603
 * BOJ 6087 레이저통신
 * 방향정보를 이용하여 최솟값 구하기
 * */

#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
char map[105][105];
int check[105][105];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int sx=-1, sy=-1, ex, ey;

struct info {
    int x,y,d,c;
};

void func(){
    queue <info> q;
    for(int i=0; i<4; i++){
        q.push({sx,sy,i,0});
    }
    check[sx][sy]=0;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        int c = q.front().c;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = c;
            
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(map[nx][ny]=='*') continue;

                if(d!=i){ // 방향이 같지 않음 -- 거울을 놓는다.
                    ncnt += 1;
                }

                if(check[nx][ny] >= ncnt){
                    check[nx][ny] = ncnt;
                    q.push({nx,ny,i,ncnt});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M >> N;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;

        for(int j=0; j<M; j++){
            map[i][j] = s[j];

            if(map[i][j]=='C'){
                if(sx==-1 && sy==-1) {
                    sx=i, sy=j;
                }
                else {
                    ex=i; ey=j;
                }
            }

            check[i][j]=INF;
        }
    }

    func();
    cout << check[ex][ey];

    return 0;
}
