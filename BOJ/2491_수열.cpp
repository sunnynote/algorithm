/**
 * @file 2491.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2491 수열 / 구현
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N;
int arr[100005];
int ans = -1;

void solve(){
  // <
  int cnt = 1;
  for(int i=1; i<N; i++){
    if(arr[i-1] > arr[i] || i == N-1){
      if(arr[i-1] <= arr[i] && i == N-1) cnt++;
      if(ans < cnt) ans = cnt;
      cnt = 0;
    }
    cnt++;
  }

  // >
  cnt = 1;
  for(int i=1; i<N; i++){
    if(arr[i-1] < arr[i] || i == N-1){
      if(arr[i-1] >= arr[i] && i == N-1) cnt++;
      if(ans < cnt) ans = cnt;
      cnt = 0;
    }
    cnt++;
  }

  if(N==1) ans = 1;
  cout << ans;
}

void input(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}