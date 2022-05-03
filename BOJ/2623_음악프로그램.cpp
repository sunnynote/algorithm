/**
 * @file 2623.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2623 음악프로그램 / 위상정렬
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
queue <int> q;
int ind[1005];
vector <int> v[1005];
vector <int> ans;

void solve(){
  for(int i=1; i<=N; i++){
    if(ind[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int x = q.front();
    q.pop();
    ans.push_back(x);

    for(int i=0; i<v[x].size(); i++){
      int nx = v[x][i];

      ind[nx]--;
      if(ind[nx]==0){
        q.push(nx);
      }
    }
  }

  if(ans.size()==0) cout << 0 << '\n';
  else{
    for(int i=0; i<ans.size(); i++){
      cout << ans[i] << '\n';
    }
  }
}

void input(){
  cin >> N >> M;

  for(int i=0; i<M; i++){
    int n, x, y;
    
    cin >> n;
    cin >> x;
    for(int j=1; j<n; j++){
      cin >> y;
      v[x].push_back(y);
      ind[y]++;
      x = y;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}