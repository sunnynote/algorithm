/**
 * @file 17509.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 17509 And the Winner Is... Ourselves! / 그리디
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

static int N = 11;
int arr[12];
int res = 0;

void solve(){
  sort(arr, arr+N);

  int cur = 0;
  int all = 0;
  for(int i=0; i<N; i++){
    cur += arr[i];
    all += cur;
  }
  
  cout << all + res << '\n';
}

void input(){
  int x;

  for(int i=0; i<N; i++){
    cin >> arr[i] >> x;
    res += (20 * x);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}