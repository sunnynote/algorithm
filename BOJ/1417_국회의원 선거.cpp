/**
 * @file 1417.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1417 국회의원 선거 / PQ
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <queue>
using namespace std;

int N, da;
int ans = 0;

priority_queue <int> q;

void solve(){
  while(!q.empty()){
    int x = q.top();
    q.pop();

    if(da > x){
      cout << ans << '\n';
      break;
    }

    ans++;
    da += 1;
    x -= 1;
    q.push(x);
  }
}

void input(){
  cin >> N;
  cin >> da;
  
  if(N==1) cout << ans << '\n';
  
  int x;
  for(int i=1; i<N; i++){
    cin >> x;
    q.push(x);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}