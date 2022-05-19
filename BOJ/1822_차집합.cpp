/**
 * @file 1822.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1822 차집합 / map
 * @version 0.1
 * @date 2022-05-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <map>
using namespace std;

int A, B;
map<int, bool> mp;

void solve(){
  cin >> A >> B;

  int x;
  for(int i=0; i<A; i++){
    cin >> x;
    mp[x] = true;
  }

  for(int i=0; i<B; i++){
    cin >> x;
    mp[x] = false;
  }

  int cnt = 0;
  for(auto it = mp.begin(); it != mp.end(); it++){
    if(it->second){
      cnt++;
    }
  }

  cout << cnt << '\n';

  for(auto it = mp.begin(); it != mp.end(); it++){
    if(it->second){
      cout << it->first << '\n';
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}