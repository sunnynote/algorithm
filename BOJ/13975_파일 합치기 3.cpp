/**
 * @file 13975.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 13975 파일 합치기 3 / 우선순위 큐
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int T, K, x;
  cin >> T;

  while(T--){
    priority_queue <long, vector<long>, greater<long> > q;

    cin >> K;

    for(int i=0; i<K; i++){
      cin >> x;
      q.push(x);
    }

    //solve
    long ans = 0;

    while(q.size() > 1){
      long a = q.top(); q.pop();
      long b = q.top(); q.pop();

      ans += (a + b);
      q.push(a + b);
    }

    cout << ans << '\n';
  }
}