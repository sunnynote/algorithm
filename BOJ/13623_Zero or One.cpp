/**
 * @file 13623.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 13623 Zero or One
 * @version 0.1
 * @date 2022-05-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int A, B, C;

void solve(){
  if(A == B && B == C){
    cout << "*";
  }
  else if(A == B){
    cout << "C";
  }
  else if(A == C){
    cout << "B";
  }
  else if(B == C){
    cout << "A";
  }
}

void input(){
  cin >> A >> B >> C;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}