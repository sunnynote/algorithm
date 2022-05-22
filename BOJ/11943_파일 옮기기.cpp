/**
 * @file 0.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 11943 파일 옮기기
 * @version 0.1
 * @date 2022-05-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int a, b, c, d;

int mx(int x, int y){
  if(x > y) return x;
  return y;
}

void solve(){
  int ans = mx(a+d, b+c);
  cout << ans << '\n';
}

void input(){
  cin >> a >> b >> c >> d;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}