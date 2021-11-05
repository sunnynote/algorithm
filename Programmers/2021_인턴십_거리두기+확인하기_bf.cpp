/**
 * 21-11-05
 * Programmers
 * 2021 인턴십
 * Lv2 거리두기 확인하기
 * Brute force
 * */

#include <string>
#include <vector>
#define N 5
using namespace std;

char map[6][6];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool func(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(0<=nx && nx<N && 0<=ny && ny<N){
            if(map[nx][ny]=='P') return false;
            if(map[nx][ny]=='X') continue;
            
            for(int j=0; j<4; j++){
                int nnx = nx + dx[j];
                int nny = ny + dy[j];
                
                if(x==nnx && y==nny) continue;
                if(0<=nnx && nnx<N && 0<=nny && nny<N){
                    if(map[nnx][nny]=='P') return false;
                }
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