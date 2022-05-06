/**
 * @file 2477.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2477 참외밭 / 구현
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int K;
int arr[6][2];

void solve(){
  int ans = -1;
  int mx = -1;

  for(int i=0; i<6; i++){
    int cur = arr[i][1] * arr[(i+1) % 6][1];

    if(mx == -1 || mx < cur){ // 곱한 값 중 가장 큰 값을 저장하고,
      mx = cur;
      // 현재 인덱스가 큰 가로 세로일 경우일 때, 작은 가로 세로가 된다.
      ans = mx - arr[(i+3) % 6][1] * arr[(i+4) % 6][1];
    }
  }

  cout << ans * K;
}

void input(){
  cin >> K;

  for(int i=0; i<6; i++){
    cin >> arr[i][0] >> arr[i][1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}