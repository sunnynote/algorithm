/**
 * @file 2890.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2890 카약
 * @version 0.1
 * @date 2023-05-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  vector <pair<int,int> > v;

  for(int i=0; i<N; i++){
    string s;
    cin >> s;

    for(int j=M-2; j>0; j--){
      if(s.at(j) != '.'){
        v.push_back({j, s.at(j) - '0'});
        break;
      }
    }
  }

  sort(v.begin(), v.end());
  
  int ans[10];
  
  int cnt = 1;
  int loc = v[v.size()-1].first;
  ans[v[v.size()-1].second] = cnt;
  
  for(int i=v.size()-2; i>=0; i--){
    if(loc == v[i].first){
      ans[v[i].second] = cnt;
    }
    else{
      ans[v[i].second] = ++cnt;
      loc = v[i].first;
    }
  }
  
  for(int i=1; i<=9; i++){
    cout << ans[i] << '\n';
  }
}