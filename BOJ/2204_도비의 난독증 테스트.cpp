/**
 * @file 2204.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2204 도비의 난독증 테스트 / 구현
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string arr[1002];
map <string, int> mp;

string change(string s){
  string res = "";

  for(int i=0; i<s.length(); i++){
    if('A' <= s[i] && s[i] <= 'Z'){
      char c = s[i] + 32;
      res += c;
    }
    else res += s[i];
  }
  return res;
}

void solve(){
  while(true){
    int N;
    cin >> N;

    if(N == 0) break;

    mp.clear();

    for(int i=0; i<N; i++){
      string s;
      cin >> s;
      arr[i] = s;

      string val = change(s);
      mp[val] = i;
    }

    cout << arr[mp.begin() -> second] << '\n';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}