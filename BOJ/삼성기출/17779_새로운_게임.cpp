#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, K;
int board[15][15];
deque <int> dq[15][15];

int dx[5]={0,0,0,-1,1};
int dy[5]={0,1,-1,0,0};

struct Horse{
    int x, y, d;
    Horse(){};
    Horse(int _x, int _y, int _d){
        x=_x; y=_y; d=_d;
    }
};
vector <Horse> h;

int main(){
    cin >> N >> K;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    h.push_back( Horse(0,0,0) );

    for(int i=1; i<=K; i++){
        int x, y, d;
        cin >> x >> y >> d;

        dq[x-1][y-1].push_back(i);
        h.push_back( Horse(x-1,y-1,d) );
    }

    int ans = 0;

    while(1){
        
        if(ans>1000) break;

        ans++;

        for(int k=1; k<=K; k++){ // turn..1번부터 K번까지
            int x = h[k].x;
            int y = h[k].y;
            int d = h[k].d;

            int nx = x + dx[d];
            int ny = y + dy[d];

            // out or 2
            if(!(0<=nx && nx<N && 0<=ny && ny<N) || board[nx][ny]==2){
                if(h[k].d==1) h[k].d=2;
                else if(h[k].d==2) h[k].d=1;
                else if(h[k].d==3) h[k].d=4;
                else h[k].d=3;

                nx = x + dx[h[k].d];
                ny = y + dy[h[k].d];

                if(!(0<=nx && nx<N && 0<=ny && ny<N) || board[nx][ny]==2) 
                    continue;
            }

            if(board[nx][ny]==0){
                bool flag = false;

                int len = dq[x][y].size();

                for(int i=0; i<len; i++){
                    int cur = dq[x][y].front();
                    dq[x][y].pop_front();

                    // 현재 idx ~ 끝까지
                    if(cur==k || flag){
                        flag=true;
                        h[cur].x = nx;
                        h[cur].y = ny;
                        dq[nx][ny].push_back(cur);
                    }

                    else dq[x][y].push_back(cur);
                }
            }

            else if(board[nx][ny]==1){
                int len = dq[x][y].size();

                for(int i=0; i<len; i++){
                    int cur = dq[x][y].back();
                    dq[x][y].pop_back();

                    dq[nx][ny].push_back(cur);
                    h[cur].x = nx;
                    h[cur].y = ny;

                    if(cur==k) break;
                }
            }

            if(dq[nx][ny].size() >= 4) {
                cout << ans;
                return 0;
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}