/**
 * @file 23841.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 23841 데칼코마니 / 구현
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N, M;
char arr[52][52];

void solve(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(arr[i][j] == '.') continue;

      arr[i][(M-1) - j] = arr[i][j];
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cout << arr[i][j];
    } cout << '\n';
  }
}

void input(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> arr[i][j];
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}