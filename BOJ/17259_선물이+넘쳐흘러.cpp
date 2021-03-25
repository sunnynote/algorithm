/**
 * 21-03-26
 * BOJ 17259 선물이 넘쳐흘러
 * 구현
 * */

#include <iostream>
#define MX 100+2
#define INF 987654321
using namespace std;

int B, N, M;
int map[MX][MX];
int ans = 0;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct Info{
    int r, c, t, cur;
};
Info arr[3*MX-6];

void move(int x, int y, int d, int v){
    if(x==B-1 && y==0)
        return;

    int nx = x + dx[d];
    int ny = y + dy[d];

    if(!(0<=nx && nx<B && 0<=ny && ny<B)){
        nx -= dx[d];
        ny -= dy[d];
        d += 1;
        nx += dx[d];
        ny += dy[d];
    }

    int nv = map[nx][ny];
    map[nx][ny] = v;
    move(nx, ny, d, nv);
}

void packing(){
    for(int i=1; i<=N; i++){
        
        if(arr[i].cur==0){ // 포장 중이 아니라면
            int mnX, mnY;
            int mnNum = INF;

            for(int k=0; k<4; k++){ 
                int nx = arr[i].r + dx[k];
                int ny = arr[i].c + dy[k];

                if(0<=nx && nx<B && 0<=ny && ny<B){
                    if(map[nx][ny] != 0 && mnNum > map[nx][ny]){
                        mnX = nx;
                        mnY = ny;
                        mnNum = map[nx][ny];
                    }
                }
            }

            if(mnNum != INF){
                ans++;
                arr[i].cur++;
                map[mnX][mnY] = 0;
            }
        }

        else arr[i].cur++; // 포장 진행

        if(arr[i].cur==arr[i].t) // 포장 완료
            arr[i].cur = 0;
    }

    move(0, 0, 0, map[0][0]);
    map[0][0] = 0;
}

void solve(){
    // 선물 올리기 M회 반복
    for(int i=1; i<=M; i++){
        map[0][0] = i;
        packing();
    }

    // 벨트에 남은 선물 처리
    while(1){
        int cnt = 0;
        for(int i=0; i<B; i++){
            if(map[0][i]!=0) cnt++;
            if(map[B-1][i]!=0) cnt++;
            if(map[i][B-1]!=0) cnt++;
        }

        if(cnt==0) break;
        packing();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> B >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> arr[i].r >> arr[i].c >> arr[i].t;

    solve();

    cout << ans << '\n';
    return 0;
}