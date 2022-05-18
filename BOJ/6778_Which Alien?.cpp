/**
 * @file 6778.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 6778 Which Alien?
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int A, E;

void solve(){
  if(3 <= A && E <= 4){
    cout << "TroyMartian\n";
  }
  if(A <= 6 && 2 <= E){
    cout << "VladSaturnian\n";
  }
  if(A <= 2 && E <= 3){
    cout << "GraemeMercurian\n";
  }
}

void input(){
  cin >> A >> E;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}