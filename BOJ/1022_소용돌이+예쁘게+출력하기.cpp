/**
 * 200602
 * BOJ 1022
 * 소용돌이 예쁘게 출력하기
 * 시뮬레이션
 * */

#include <iostream>
using namespace std;

int r1, c1, r2, c2;
int map[51][6];

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

int maxNum=-1;

void makeMap(){
  int x=0, y=0, dir=0;
  int num=1;
  int cnt=0, dcnt=1; // 몇 칸 이동중인지

  while(1){
    if(map[0][0]!=0 && map[r2-r1][c2-c1]!=0 && map[0][c2-c1]!=0 && map[r2-r1][0]!=0) break;

    if(r1<=x && x<=r2 && c1<=y && y<=c2){
      map[x-r1][y-c1] = num;
      maxNum = num;
    }

    num++; // map의 숫자 증가
    cnt++; // 전진 카운트 증가

    x += dx[dir];
    y += dy[dir];

    if(cnt==dcnt){ // dcnt만큼 전진 후
      cnt = 0;

      // 방향이 2번 바뀔 때마다 진행해야 하는 카운트 증가
      dir = (dir+1)%4;
      if(dir==0 || dir==2) dcnt++;
    }
  }
}

int getLength(int n){
  int ret=0;
  while(n!=0){
    n/=10;
    ret++;
  }
  return ret;
}

void printMap(){
  int maxLen = getLength(maxNum);

  for(int i=0; i<=(r2-r1); i++){
    for(int j=0; j<=(c2-c1); j++){

      int len = getLength(map[i][j]);

      for(int k=0; k<maxLen-len; k++)
        cout << ' ';
      
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;

    makeMap();
    printMap();

    return 0;
}

