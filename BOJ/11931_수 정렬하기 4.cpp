/**
 * @file 11931.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 11931 수 정렬하기 4
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> v;

void solve(){
  for(int i=N-1; i>=0; i--){
    cout << v[i] << '\n';
  }
}

void input(){
  cin >> N;
  
  int x;
  for(int i=0; i<N; i++){
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}