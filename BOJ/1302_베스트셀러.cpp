/**
 * @file 1302.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1302 베스트셀러 / MAP
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <map>
using namespace std;

int N;
map <string,int> mp;

void solve(){
  cin >> N;
  
  string s;
  for(int i=0; i<N; i++){
    cin >> s;
    
    if(mp.find(s) == mp.end()){
      mp.insert({s, 1});
    }
    else{
      mp[s]++;
    }
  }

  int mx = -1;
  string ans = "";
  for(auto it = mp.begin(); it!=mp.end(); it++){
    if(mx < it->second){
      ans = it->first;
      mx = it->second;
    }
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}