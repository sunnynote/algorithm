/**
 * @file 16208.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 16208 귀찮음 /그리디
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int N;
int arr[5005];
int tot = 0;

void solve(){
  long ans = 0;

  for(int i=0; i<N; i++){
    tot -= arr[i];
    ans += (tot * arr[i]);
  }

  cout << ans;
}

void input(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> arr[i];
    tot += arr[i];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}