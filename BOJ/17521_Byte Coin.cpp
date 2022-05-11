/**
 * @file 17521.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 17521 Byte Coin / 그리디
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int N, W;
int arr[16];

long long w = 0;
long long coin = 0;

void solve(){
  w = W;

  for(int i=1; i<=N; i++){
    if(arr[i] > arr[i+1]){
      w += coin * arr[i];
      coin = 0;
    }

    if(arr[i] < arr[i+1]){
      long long tmp = w / arr[i];
      w -= (tmp * arr[i]);
      coin += tmp;
    }
  }

  w += coin * arr[N];

  cout << w << '\n';
}

void input(){
  cin >> N >> W;
  for(int i=1; i<=N; i++){
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