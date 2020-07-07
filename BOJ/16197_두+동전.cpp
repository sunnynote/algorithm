/**
 * 200704
 * BOJ 16197 두 동전
 * BFS
 * */

#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[22][22];

struct Info{
    int x1, y1, x2, y2;
};

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int bfs(int x1, int y1, int x2, int y2){
    int ans = 0;
    
    queue <Info> q;
    q.push({x1,y1,x2,y2});
    
    while(1){
        ans++;   
        if(ans>10) {
            ans = -1;
            return ans;
        }

        int q_size = q.size();
        
        while(q_size--){
            x1 = q.front().x1;
            y1 = q.front().y1;
            x2 = q.front().x2;
            y2 = q.front().y2;
            q.pop();

            for(int i=0; i<4; i++){
                int nx1 = x1 + dx[i];
                int ny1 = y1 + dy[i];
                int nx2 = x2 + dx[i];
                int ny2 = y2 + dy[i];

                // 1 O -- 2 O,X 
                if(0<=nx1 && nx1<N && 0<=ny1 && ny1<M){
                    if((0<=nx2 && nx2<N && 0<=ny2 && ny2<M)){
                        if(map[nx1][ny1]=='#' && map[nx2][ny2]=='#')
                            q.push({x1, y1, x2, y2});

                        else if(map[nx1][ny1]=='#' 
                        && (map[nx2][ny2]=='.' || map[nx2][ny2]=='o') ){
                            map[x2][y2]='.';
                            map[nx2][ny2]='o';
                            q.push({x1, y1, nx2, ny2});
                        }

                        else if( (map[nx1][ny1]=='.' || map[nx1][ny1]=='o')
                        && map[nx2][ny2]=='#'){
                            map[x1][y1]='.';
                            map[nx1][ny1]='o';
                            q.push({nx1, ny1, x2, y2});
                        }
                        
                        else if(map[nx1][ny1]!='#' && map[nx2][ny2]!='#'){
                            map[x1][y1]='.'; map[x2][y2]='.';
                            map[nx1][ny1]='o'; map[nx2][ny2]='o';
                            q.push({nx1, ny1, nx2, ny2});
                        }
                    }

                    if(!(0<=nx2 && nx2<N && 0<=ny2 && ny2<M)){
                        return ans;
                    }
                }

                // 1 X -- 2 O X
                if(!(0<=nx1 && nx1<N && 0<=ny1 && ny1<M)){
                    if(0<=nx2 && nx2<N && 0<=ny2 && ny2<M){
                        return ans;
                    }

                    if(!(0<=nx2 && nx2<N && 0<=ny2 && ny2<M))
                        continue;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int tmpx1=-1, tmpy1=-1, tmpx2=-1, tmpy2=-1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];

            if(map[i][j]=='o'){
                if(tmpx1==-1 && tmpy1==-1)
                    tmpx1=i, tmpy1=j;
                else tmpx2=i, tmpy2=j;
            }
        }
    }

    cout << bfs(tmpx1, tmpy1, tmpx2, tmpy2);
    return 0;
}