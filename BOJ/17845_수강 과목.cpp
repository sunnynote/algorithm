/**
 * @file 17845.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 17845 수강 과목 / DP
 * @version 0.1
 * @date 2022-05-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N, K;
int arr[1005][2];
int d[1005][10005]; // [과목수][공부시간]

int mx(int a, int b){
  if(a > b) return a;
  return b;
}

void solve(){
  for(int i=1; i<=K; i++){
    for(int j=0; j<=N; j++){
      if(j - arr[i][1] >= 0){
        d[i][j] = mx(d[i-1][j-arr[i][1]] + arr[i][0], d[i-1][j]);
      }
      else{
        d[i][j] = d[i-1][j];
      }
    }
  }

  cout << d[K][N];
}

void input(){
  cin >> N >> K;
  for(int i=1; i<=K; i++){
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