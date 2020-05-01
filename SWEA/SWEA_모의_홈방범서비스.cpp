#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
 
int N, M;
int map[25][25];
int check[25][25]; // depth number
int ans=0;
 
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
 
int operPrice[25];
int house[25];
 
void bfs(int x, int y){
    memset(house, 0, sizeof(house));
    memset(check, 0, sizeof(check));
 
    queue <pair<int,int> > q;
    q.push(make_pair(x,y));
    check[x][y]=1;
 
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
         
        if(map[x][y]==1) house[ check[x][y] ]++;
        if(check[x][y] > N+1) return;
 
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if(0<=nx && nx<N && 0<=ny && ny<N){
                if(check[nx][ny]==0){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = check[x][y]+1;
                }
            }
        }
    }
 
}
 
int calc(){
    int res=0;
    int house_sum=0;
    for(int i=1; i<=N+1; i++){
        house_sum += house[i];
        int profit = house_sum * M - operPrice[i];
        if(profit >= 0) res = max(res, house_sum);
    }
    return res;
}
 
int main(int argc, char** argv){
    int test_case, T;
    cin >> T;
 
    for(test_case=1; test_case<=T; test_case++){
        //init
        memset(map, 0, sizeof(map));
        ans = 0;
 
        cin >> N >> M;
         
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> map[i][j];
 
        // 각 크기의 운영 비용 미리 계산
        for(int i=1; i<=N+1; i++)
            operPrice[i] = i*i + (i-1)*(i-1);
 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                // 모든 정점에서 확인하기
                bfs(i, j);
                ans = max(ans, calc());
            }
        }
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}