/**
 * @file 6159.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 6159 코스튬 파티
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int N, S;
int arr[20005];

void solve(){
  int ans = 0;

  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      if(arr[i] + arr[j] <= S) ans++;
    }
  }

  cout << ans;
}

void input(){
  cin >> N >> S;
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