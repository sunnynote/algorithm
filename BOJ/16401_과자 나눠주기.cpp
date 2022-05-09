/**
 * @file 16401.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 16401 과자 나눠주기 / 이분탐색
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

int M, N;
int arr[1000005];
int ans = 0;

bool func(int n){
  int cnt = 0;

  for(int i=0; i<N; i++){
    if(arr[i] >= n){
      cnt += (arr[i] / n);
    }
  }

  if(cnt >= M) return true;
  return false;
}

void solve(){
  int l = 1;
  int r = 1000000000;

  while(l <= r){
    int mid = (l + r) / 2;
    
    if(func(mid)){
      ans = mid;
      l = mid + 1;      
    }
    else{
      r = mid - 1;
    }
  }

  cout << ans << '\n';
}

void input(){
  cin >> M >> N;
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }

  sort(arr, arr+N);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}