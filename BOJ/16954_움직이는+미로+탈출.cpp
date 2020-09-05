/**
 * 200905
 * BOJ 16954 움직이는 미로 탈출
 * BFS
 * */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N=8;
char map[9][9];
bool check[9][9];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={-1,1,1,-1,0,1,-1,0};

bool exitFlag=true;

void solveBFS(){
    queue <pair<int,int> > q;
    q.push(make_pair(7,0));
    for(int i=0; i<8; i++){
        int nx = 7 + dx[i];
        int ny = 0 + dy[i];

        if(0<=nx && nx<N && 0<=ny && ny<N){
            if(map[nx][ny]=='.') q.push(make_pair(nx,ny));
        }
    }

    while(1){
        if(q.empty()) {
            exitFlag=false; break;
        }
        memset(check, 0, sizeof(check));
        int q_size = q.size();

        // <-- map move start -->
        char nmap[9][9];
        for(int i=N; i>1; i--)
            for(int j=0; j<N; j++)
                nmap[i-1][j] = map[i-2][j]; 
        for(int i=0; i<N; i++)
            nmap[0][i] = '.';

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                map[i][j] = nmap[i][j];
        // <-- map move end -->

        while(q_size--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(map[x][y]=='#') continue;
            
            if(x==0 && y==N-1) {
                return;
            }

            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<N){
                    if(!check[nx][ny] && map[nx][ny]=='.'){
                        q.push(make_pair(nx,ny));
                        check[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    for(int i=0; i<N; i++)
        cin >> map[i];
    
    solveBFS();

    if(!exitFlag) cout << 0;
    else cout << 1;

    return 0;
}