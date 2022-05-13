/**
 * @file 19939.Cpp
 * @author your name (you@domain.com)
 * @brief BOJ 19939 박 터뜨리기 / 그리디
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N, K;
int ans = 0;
int sum = 0;

void solve(){
  for(int i=1; i<=K; i++){
    sum += i;
  }
  
  N -= sum;

  if(N < 0){
    ans = -1;
  }
  else{
    if(N % K == 0) ans = K - 1;
    else ans = K;
  }

  cout << ans << '\n';
}

void input(){
  cin >> N >> K;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}