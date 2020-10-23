/**
 * 20-10-06
 * 구슬 탈출
 * BFS
 * */

#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[12][12];
int check[12][12][12][12];
int RX, RY, BX, BY;

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

struct Info{
    int x, y, z, w;
};

int solve(int rx, int ry, int bx, int by){
    queue <Info> q;
    q.push({rx,ry,bx,by});
    check[rx][ry][bx][by] = true;
    int cnt = 0;

    while(!q.empty()){
        int qs = q.size();

        while(qs--){
            rx = q.front().x;
            ry = q.front().y;
            bx = q.front().z;
            by = q.front().w;
            q.pop();

            if(cnt>10) return -1; 

            if(map[rx][ry]=='O' && map[bx][by]!='O'){
                return cnt;
            }

            for(int i=0; i<4; i++){
                int nrx = rx;
                int nry = ry;
                int nbx = bx;
                int nby = by;

                while(1){
                    if(map[nrx+dx[i]][nry+dy[i]]=='#' || map[nrx][nry]=='O') break;
                    nrx += dx[i]; nry += dy[i];
                }

                while(1){
                    if(map[nbx+dx[i]][nby+dy[i]]=='#' || map[nbx][nby]=='O') break;
                    nbx += dx[i]; nby += dy[i];
                }

                if(nrx==nbx && nry==nby){
                    if(map[nbx][nby]=='O') continue;

                    if(abs(nrx-rx) + abs(nry-ry) > abs(nbx-bx)+abs(nby-by)){
                        nrx -= dx[i];
                        nry -= dy[i];
                    }
                    else{
                        nbx -= dx[i];
                        nby -= dy[i];
                    }
                }

                if(!check[nrx][nry][nbx][nby]){
                    q.push({nrx,nry,nbx,nby});
                    check[nrx][nry][nbx][nby] = true;
                }
            }
        }

        cnt++;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j] = s[j];
            if(map[i][j]=='R') {
                RX = i; RY = j;
                map[i][j]='.';
            }
            if(map[i][j]=='B'){
                BX = i; BY = j;
                map[i][j]='.';
            }
        }
    }
    
    int ans = solve(RX, RY, BX, BY);

    if(ans==-1) cout << 0 << '\n';
    else cout << 1 << '\n';

    return 0;
}
