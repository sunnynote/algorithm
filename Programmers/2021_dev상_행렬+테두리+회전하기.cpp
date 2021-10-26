/**
 * 21-10-26
 * Programmers
 * 2021 Dev-Matching: 웹 백엔드 개발자(상반기)
 * 행렬 테두리 회전하기
 * */

#include <string>
#include <vector>
using namespace std;

int map[105][105];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int x1, y1, x2, y2;
vector <int> v;

void dfs(int sx, int sy, int x, int y, int d, int val){
    v.push_back(val);
    
    if(sx==x && sy==y && d!=0) return;
    
    int nx = x + dx[d];
    int ny = y + dy[d];
    
    if( !(x1<=nx && nx<=x2 && y1<=ny && ny<=y2) ){ // 범위를 벗어난다면
        
        nx -= dx[d];
        ny -= dy[d];
        
        nx += dx[d+1];
        ny += dy[d+1];
        
        int tmp_val = map[nx][ny];
        map[nx][ny] = val;
         
        dfs(sx, sy, nx, ny, d+1, tmp_val);
    }
    else{ // 범위를 벗어나지 않는다면
        int tmp_val = map[nx][ny];
        map[nx][ny] = val;
        
        dfs(sx, sy, nx, ny, d, tmp_val);
    }
    
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int cnt = 1;
    for(int i=1; i<=rows; i++)
        for(int j=1; j<=columns; j++)
            map[i][j] = cnt++;
    
    for(int i=0; i<queries.size(); i++){
        v.clear();
        
        x1 = queries[i][0];
        y1 = queries[i][1];
        x2 = queries[i][2];
        y2 = queries[i][3];
        
        dfs(x1, y1, x1, y1, 0, map[x1][y1]);
        
        int res = 987654321;
        for(int j=0; j<v.size(); j++)
            if(v[j] < res) res = v[j];
        
        answer.push_back(res);
    }
    
    return answer;
}