/**
 * 200605
 * BOJ 1986 체스
 * 시뮬레이션
 * */

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[1005][1005];

struct info{
    int x, y;
};
vector <info> q;
vector <info> k;

int qx[8]={-1,-1,-1,0,0,1,1,1};
int qy[8]={-1,0,1,-1,1,-1,0,1};
int kx[8]={-2,-2,-1,-1,1,1,2,2};
int ky[8]={-1,1,-2,2,-2,2,-1,1};

void solve(){
    //Q
    for(int i=0; i<q.size(); i++){
        int x = q[i].x;
        int y = q[i].y;

        for(int j=0; j<8; j++){
            int nx = x + qx[j];
            int ny = y + qy[j];

            while(1){
                if(!(0<nx && nx<=N && 0<ny && ny<=M)) break;
                if(map[nx][ny]==2 || map[nx][ny]==3) break;

                if(map[nx][ny]==0) map[nx][ny]=4;
                nx += qx[j];
                ny += qy[j];
            }
        }
    }

    //K
    for(int i=0; i<k.size(); i++){
        int x = k[i].x;
        int y = k[i].y;
        
        for(int j=0; j<8; j++){
            int nx = x + kx[j];
            int ny = y + ky[j];

            if(0<nx && nx<=N && 0<ny && ny<=M){
                if(map[nx][ny]==0) map[nx][ny]=5;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    int Q, K, P, x, y;

    cin >> Q; // Queen
    for(int i=0; i<Q; i++){
        cin >> x >> y;
        map[x][y] = 1;
        q.push_back({x,y});
    }
    cin >> K; // Knight
    for(int i=0; i<K; i++){
        cin >> x >> y;
        map[x][y] = 2;
        k.push_back({x,y});
    }
    cin >> P; // Pawn
    for(int i=0; i<P; i++){
        cin >> x >> y;
        map[x][y] = 3;
    }

    solve();

    int ans = 0;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(map[i][j]==0) ans++;

    cout << ans << '\n';

    return 0;
}