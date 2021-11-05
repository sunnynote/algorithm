/**
 * 21-11-05
 * Programmers
 * 2021 인턴십
 * Lv2 거리두기 확인하기
 * BFS
 * */

#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define N 5
using namespace std;

char map[6][6];
int chk[6][6];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool func(int sx, int sy){
    queue <pair<int,int> > q;
    memset(chk, -1, sizeof(chk));

    q.push({sx, sy});
    chk[sx][sy] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(chk[x][y]>=2) continue;
        
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0<=nx && nx<N && 0<=ny && ny<N){
                if(chk[nx][ny]!=-1 || map[nx][ny]=='X') continue;
                
                if(map[nx][ny]=='P') return false;
                
                q.push({nx, ny});
                chk[nx][ny] = chk[x][y] + 1;
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int p=0; p<places.size(); p++){
        for(int i=0; i<N; i++){
            string s = places[p][i];
            for(int j=0; j<N; j++)
                map[i][j] = places[p][i][j];
        }
        
        bool f = true;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j]=='P') {
                    f = func(i, j);
                    if(!f) break;
                }
            }
            if(!f) break;
        }
        
        answer.push_back(f);
    }
    
    return answer;
}