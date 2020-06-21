/**
 * 200620
 * BOJ 2234
 * 성곽
 * BFS + BIT MASK
 * */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[101][101];
int check[101][101];

struct Info{
  int x, y;
};

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int bfs(int x, int y){
  queue <Info> q;
  q.push({x,y});
  int roomNum = 0;
  check[x][y] = ++roomNum;
  
  while(!q.empty()){
    x = q.front().x;
    y = q.front().y;
    q.pop();

    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(0<=nx && nx<N && 0<=ny && ny<M){
        if(map[x][y] & (1<<i)) continue;

        if(check[nx][ny]==0){
          q.push({nx,ny});
          check[nx][ny] = ++roomNum;
        }
      }
    }

  }
  return roomNum;
}

int main(){
  cin >> M >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      cin >> map[i][j];

  int ansA = 0;
  int ansB = -1;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(check[i][j]==0){
        ansA++;
        ansB = max(ansB, bfs(i,j));
      }
    }
  }

  memset(check,0,sizeof(check));

  int ansC = -1;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){

      for(int k=0; k<4; k++){
        // 벽이 있으면
        if( (map[i][j] & 1<<k) == 1<<k){
          memset(check,0,sizeof(check));
          
          // 벽 제거
          map[i][j] -= (1<<k);
          ansC = max(ansC, bfs(i,j));
          map[i][j] += (1<<k);
        }
      }
      
    }
  }
  
  cout << ansA << '\n';
  cout << ansB << '\n';
  cout << ansC << '\n';
  return 0;
}