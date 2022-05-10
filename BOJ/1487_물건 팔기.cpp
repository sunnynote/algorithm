/**
 * @file 1487.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1487 물건 팔기 / 구현
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <pair<int, int> > v;

bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

void solve(){
  sort(v.begin(), v.end(), cmp);

  int ans = 0;
  int mx = 0;

  for(int i=0; i<N; i++){ // 모든 가격 적용
    int tot = 0;

    for(int j=i; j<N; j++){
      if(v[i].first > v[j].second){
        tot += (v[i].first - v[j].second);
      }
    }

    if(mx < tot){
      mx = tot;
      ans = v[i].first;
    }
  }

  cout << ans << '\n';
}

void input(){
  cin >> N;
  
  int a, b;
  for(int i=0; i<N; i++){
    cin >> a >> b;
    v.push_back({a, b});
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}