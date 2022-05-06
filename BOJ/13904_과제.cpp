/**
 * @file 13904.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 13904 과제 / 그리디
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <pair<int,int> > v;
int res[1005];

bool cmp(pair<int, int> a, pair<int, int> b){
  if(a.second == b.second){
    return  a.first > b.first;
  }
  return a.second > b.second;
}

void solve(){
  sort(v.begin(), v.end(), cmp);

  for(int i=0; i<N; i++){
    int d = v[i].first;
    int w = v[i].second;

    if(res[d] == 0){
      res[d] = w;
    }
    else{
      int idx = d-1;
      while(1){
        if(idx == 0) break;

        if(res[idx] == 0){
          res[idx] = w;
          break;
        }
        else idx--;
      }
    }
  }

  int ans = 0;
  for(int i=1; i<=1000; i++){
    ans += res[i];
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