/**
 * @file 2166.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2166 다각형의 면적 / 기하학
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N;
double x[10001], y[10001];
double ans = 0;

double calc(int a, int b, int c){
  double val = (y[b] - y[a]) * (x[c] - x[a]) 
                  - (x[b] - x[a]) * (y[c] - y[a]);
  return val / 2;
}

void solve(){
  for(int i=1; i<N-1; i++){
    ans += calc(0, i, i+1);
  }
}

void input(){
  cin >> N;

  for(int i=0; i<N; i++){
    cin >> x[i] >> y[i];
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    cout.precision(1);
    cout << fixed;
    cout << abs(ans);

    return 0;
}