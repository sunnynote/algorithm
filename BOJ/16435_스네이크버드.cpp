/**
 * @file 16435.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 16435 스네이크버드 / 그리디
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector <int> v;

void solve(){
  sort(v.begin(), v.end());

  for(int i=0; i<N; i++){
    if(v[i] <= L){
      L++;
    }
    else break;
  }

  cout << L << '\n';
}

void input(){
  cin >> N >> L;

  int x;
  for(int i=0; i<N; i++){
    cin >> x;
    v.push_back(x);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}