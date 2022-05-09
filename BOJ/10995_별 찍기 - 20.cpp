/**
 * @file 10995.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 10995 별 찍기 - 20
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N;

void solve(){
  for(int i=0; i<N; i++){
    for(int j=0; j<2*N; j++){
      if((i+j) % 2 == 0) cout << "*";
      else cout << " ";
    } cout << '\n';
  }
}

void input(){
  cin >> N;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}